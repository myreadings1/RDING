#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "inttypes.h"
#include <math.h>

#include <stdbool.h>
#include <string.h>
#include <signal.h>




#define SEQUENCE_LENGTH 13000000
#define N_EXP 		1000
#define MISS_PRED	100
#define FP_RATE		101
#define FN_RATE		102

struct _loc_data
{
	double * values ;
	double * x;
	double * PDF;
	double * CDF;
	int 	data_size;
	int 	PDF_size;
};
////////////////////////////////////////////////////////
void 	_init_loc_data 		( struct _loc_data * ldata, const int size);
void 	_deInit_loc_data 	( struct _loc_data * ldata );
uint8_t char_to_int 		(char c);
static int count_bits 		(uint8_t n);
int 	load_raw_data 		( struct _loc_data * ldata, const int max_pkts_to_read , uint8_t which_data , const char * fname);
int 	compare 		(const void * a, const void * b);
int 	Jun_SE 			(struct _loc_data  *ldata);
int 	SD_SEM 			(struct _loc_data  *ldata);
int 	PDF_CDF 		(struct _loc_data  *ldata);
int 	read_raw_data_3est 	( char *fname );
int 	read_raw_data_2est 	( char *fname );
//////////////////////////////////////////////////////////////////////

//int main (int argc, char *argv[])
int main (  )
{

	int n_readings ;
	char fname [] = "afh_est_svm_jam20_5", buf [256];

	struct _loc_data  ldata;
	_init_loc_data ( & ldata, SEQUENCE_LENGTH );

//	if ( argc != 2) {
//		printf("usage: %s [filename]\n", argv[0]);
//		goto out;
//	}



	// 1) get data sample data from file and output raw data to file
//	read_raw_data_3est ( fname );
	read_raw_data_2est ( fname );

	sprintf (buf, "%s_raw", fname);

	// 2) load raw data from file, CAUTION: specify one of the three
	n_readings = load_raw_data ( &ldata, 1000000, MISS_PRED , buf);
//	n_readings = load_raw_data ( &ldata, 1000000, FP_RATE , buf);
//	n_readings = load_raw_data ( &ldata, 1000000, FN_RATE , buf);

	ldata.data_size = n_readings;


	// 3) sort sample data
	qsort ( ldata.values, n_readings, sizeof(double), compare );

	// 4) get PDF and CDF
	PDF_CDF ( &ldata);

	// 5) find SD and SE
	SD_SEM  ( &ldata);

	// 6) find Jun SE SD
	Jun_SE  ( &ldata);


out:
	_deInit_loc_data ( & ldata );
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////

void _init_loc_data ( struct _loc_data * ldata, const int size)
{
	ldata->values 	= (double  *) malloc ( size );
	ldata->x 	= (double  *) malloc ( size );
	ldata->PDF 	= (double  *) malloc ( size );
	ldata->CDF 	= (double  *) malloc ( size );
}
void _deInit_loc_data (  struct _loc_data * ldata )
{
	free ( ldata->values 	);
	free ( ldata->x 	);
	free ( ldata->PDF 	);
	free ( ldata->CDF 	);
}

/////////////////////////////////////////////////////////////////////////////////
uint8_t char_to_int ( char c)
{

	switch ( c )
	{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case 'A': case 'a': return 10;
		case 'B': case 'b': return 11;
		case 'C': case 'c': return 12;
		case 'D': case 'd': return 13;
		case 'E': case 'e': return 14;
		case 'F': case 'f': return 15;
		default: 
			printf ("Err ch_to_int\n");
			exit (1);
			return 255;
	}


}
//////////////////////////////////////////////////////////////////////////
static int count_bits (uint8_t n)
{
	int i = 0;
	for (i = 0; n != 0; i++)
		n &= n - 1;
	return i;
}

///////////////////////////////////////////////////////////
int load_raw_data ( struct _loc_data * ldata, const int max_pkts_to_read , uint8_t which_data ,const char * fname)
{

	FILE * pFile;
	int n_pkts ;
	double miss_pred_rate, fp_rate, fn_rate;	

	pFile = fopen (fname,"r"); 
	if (NULL == pFile) { printf ("Err open file"); goto out; }

	n_pkts = 0 ;
// Read pkt loop
	while ( 1 )
	{

		fscanf (pFile, "%lf, %lf, %lf", &miss_pred_rate, &fp_rate, &fn_rate );

		if ( feof(pFile) || (max_pkts_to_read <= n_pkts) ) 
			break;

		switch ( which_data )
		{
			case MISS_PRED:
				ldata->values [ n_pkts ] = miss_pred_rate;
				break;

			case FP_RATE:
				ldata->values [ n_pkts ] = fp_rate;
				break;

			case FN_RATE:
				ldata->values [ n_pkts ] = fn_rate;
				break;

		}

		++ n_pkts;
	}

	fclose (pFile);
	return n_pkts;

out:
	return 0;

}

///////////////////////////////////////////////////////////

int compare (const void * a, const void * b)
{
  double fa = *(const double*) a;
  double fb = *(const double*) b;
  return (fa > fb) - (fa < fb);
}
//////////////////////////////////////////////////////////

int Jun_SE (struct _loc_data  *ldata)
{

	double cdf[79][2], n_err[N_EXP], rnd, avg, var, dev;
	int i, n;

//	srand ( time(NULL) );

	for (n = 0; n < N_EXP; ++n) 
	{
		rnd = ( rand() % 1000000) / 1000000.0 ;
		for (i = 0; i < ldata->PDF_size; i++) 
		{
			if ( rnd < ldata->CDF [ i ] ) 
			{
				break;
			}
		}
		n_err [ n ] = ldata->CDF [ i ];
	}

	avg = 0;
	for (n = 0; n < N_EXP; ++n) 
	{
		avg += n_err[n];
	}
	avg /= N_EXP;

	var = 0;
	for (n = 0; n < N_EXP; ++n) {
		var += (avg-n_err[n])*(avg-n_err[n]);
	}
	var /= (N_EXP * 1.0);
	dev = sqrt(var);

	printf("%f %f %f\n", avg, avg-dev/2, avg+dev/2);
	return 0;
}
///////////////////////////////////////////////////////////
// data must be sorted array
//int PDF_CDF ( double *data, double *CDF_list , int data_size)
int SD_SEM (struct _loc_data  *ldata)
{

	int i;
	double SE, SD, VAR = 0.0, s_mean = 0.0, SUM = 0.0;

	for ( i = 0; i < ldata->data_size; i ++ )
	{
		SUM = SUM + ldata->values [ i ];

	}

	s_mean = SUM / (ldata->data_size * 1.0);

	printf ("s_mean = %f\n", s_mean);

	for ( i = 0; i < ldata->data_size; i ++ )
	{

		VAR = VAR + ((ldata->values [ i ] - s_mean) * (ldata->values [ i ] - s_mean)  );
	}

	VAR = VAR / ((  ldata->data_size -1 ) * 1.0);
	SD = sqrt ( VAR);
	SE = SD / sqrt (  ldata->data_size -1  );

	printf ("S^2 = %f, SD=%f, SE=%f\n", VAR, SD, SE   );

}
////////////////////////////////////////////////////////////
int PDF_CDF (struct _loc_data  *ldata)
{

	int elem_in_CDF_list, n_elem, i; 
	double freq, accu_CDF, curr_elem = 123456789.0; // just a random number (double) to start with

	curr_elem = ldata->values [ 0 ];
	n_elem = 0, freq = 0.0 ;


	for ( i = 0; i < ldata->data_size; i ++ )
	{
		if ( curr_elem == ldata->values [ i ] )
		{
			++ freq ; 
		}

		else //curr_elem != ldata->values [ i ]
		{
			// if yes, then 1) store this new elem; 2) put 1 in it's freq. PDF
			ldata->x 	[ n_elem ] 	= curr_elem ; 
			ldata->PDF 	[ n_elem ]	= freq / ldata->data_size;
			++ n_elem;


			curr_elem 			= ldata->values [ i ];
			freq = 1.0;
		}

	}

	ldata->x 	[ n_elem ] 	= curr_elem ; 
	ldata->PDF 	[ n_elem ]	= freq / ldata->data_size;
	++ n_elem;

	ldata->PDF_size = n_elem ; 

	accu_CDF = 0.0;
	printf ("#x, PDF, CDF\n");
	for ( i = 0; i < n_elem ; i ++ )
	{
		accu_CDF 		= accu_CDF + ldata->PDF [ i ];
		ldata->CDF [ i ]	= accu_CDF;
		printf ("%lf, %lf, %lf\n", ldata->x [ i ], ldata->PDF [ i ] , ldata->CDF [ i ]);
	}
	
	return n_elem;

}


//////////////////////////////////////////////////////////////////////////
int read_raw_data_3est ( char *fname )

{

	FILE *f_in, *f_out;

	int readings = 0, i, k, diff_bits = 0, FP_bits = 0, FN_bits = 0;
	double zeros, ones, MSP_vec = 0.0, FP_vec = 0.0, FN_vec = 0.0;
	uint8_t  E_bit, G_bit, E, G, fst_char, str1 = 0, str2 = 0, str_E [30], str_G [30];
	char buf [ 1024 ], *pch, fst_ch;


	f_in = fopen (fname,"r");
	if (NULL == f_in) { printf ("Err open file"); exit (0); }//goto out; }

	sprintf (buf, "%s_raw", fname);

	f_out = fopen (buf,"w");
	if (NULL == f_out) { printf ("Err open file"); exit (0); }//goto out; }


/// results file header
//	printf ("#MISS, FP, FN\n");

	while ( NULL != fgets(buf, 1024, f_in) )

	{
		if (feof(f_in)) break;


		if  ( NULL == (pch = strtok(buf, " ,.")) )
		{	
			printf ("Err Nul in pch\n");
			break ;
		}


		fst_ch 	 = pch [ 0 ];

		if  ( '1' ==  fst_ch   ) 
		{

			if ( NULL == (pch = strtok (NULL, " ,.")) ) 
			{ printf ("Err Nul in pch\n"); break ; }


//			printf ("%s\n", pch);

			if ( 0 != memcmp ("00000000000000000000", pch, 20))
			{
				memcpy ( str_G, pch, 20);
				str1 = 1;
			}
			
			else 
			{
//				printf ("%s\n", pch);
				str1 = 0;
				str2 = 0;
				continue;
			}
		}

		if  ( '2' ==  fst_ch   ) 
		{

			if ( NULL == (pch = strtok (NULL, " ,.")) ) 
			{ printf ("Err Nul in pch\n"); break ; }


			if ( 0 != memcmp ("00000000000000000000", pch, 20))
			{
//				strncpy ( str_E, pch, 20);
//				str2 = 1;
			}
			
			else 
			{
//				printf ("%s\n", pch);
				str1 = 0;
				str2 = 0;
				continue;
			}
		}

		if  ( '3' ==  fst_ch   ) 
		{

			if ( NULL == (pch = strtok (NULL, " ,.")) ) 
			{ printf ("Err Nul in pch\n"); break ; }


			if ( 0 != memcmp ("00000000000000000000", pch, 20))
			{
				memcpy ( str_E, pch, 20);
				str2 = 1;
			}
			
			else 
			{
//				printf ("%s\n", pch);
				str1 = 0;
				str2 = 0;
				continue;
			}
		}


		if ( str1 && str2 )
		{
			
			str1 = 0;
			str2 = 0;

			++ readings ; 
			diff_bits = 0;
			FP_bits = 0; 
			FN_bits = 0;
			zeros = 0.0;
			ones  = 0.0;

			for ( i = 0; i < 20; i++  )
			{

				G = char_to_int ( str_G [ i ]  );
				E = char_to_int ( str_E [ i ]  );

//				printf ("%x:%x:%d\n", E, G, diff_bits );
				diff_bits += count_bits ( E ^ G );

				//////////////////////////////
				for ( k = 0; k < 4 ; k ++ )
				{
//					++ total_no_bits;
					G_bit = 0x01 & ( G >> k );
					E_bit = 0x01 & ( E >> k );


					switch ( G_bit )
					{
						case 1:
							++ ones;
							if ( 0 == E_bit )
								++ FN_bits;
							break;
						case 0:
							++ zeros;
							if ( 1 == E_bit )
								++ FP_bits;
							break ;
						default:
							printf ("Err 0s and 1s\n");
							goto out;

					}
				}

			}

//			if ( 0 != diff_bits )
			{


//FPR = FP / (FP+TN) = FP / all zeros
//FNR = FN / (FN+TP) = FN / all ones

				MSP_vec = diff_bits / 79.0 ;  

				if (0 == (zeros -1.0 ))
					FP_vec = 0.000;

				else	
					FP_vec = FP_bits /  (zeros - 1.0);

				if (0 == ones)
					FN_vec = 0.000;

				else	
					FN_vec = FN_bits /  ones;


				fprintf (f_out, "%f, %f, %f\n",  MSP_vec, FP_vec, FN_vec );

			}
			
		}

//	if ( 2 < readings ) 
//		break ;
	}
//////////////////////////
out:
	fclose (f_in);
	fclose (f_out);
	return 0;

}
////////////////////////////////////////////////////////
int read_raw_data_2est ( char *fname )

{

	FILE *f_in, *f_out;

	int readings = 0, i, k, diff_bits = 0, FP_bits = 0, FN_bits = 0;
	double zeros, ones, MSP_vec = 0.0, FP_vec = 0.0, FN_vec = 0.0;
	uint8_t  E_bit, G_bit, E, G, fst_char, str1 = 0, str2 = 0, str_E [30], str_G [30];
	char buf [ 1024 ], *pch, fst_ch;


	f_in = fopen (fname,"r");
	if (NULL == f_in) { printf ("Err open file"); exit (0); }//goto out; }

	sprintf (buf, "%s_raw", fname);

	f_out = fopen (buf,"w");
	if (NULL == f_out) { printf ("Err open file"); exit (0); }//goto out; }


/// results file header
//	printf ("#MISS, FP, FN\n");

	while ( NULL != fgets(buf, 1024, f_in) )

	{
		if (feof(f_in)) break;


		if  ( NULL == (pch = strtok(buf, " ,.")) )
		{	
			printf ("Err Nul in pch\n");
			break ;
		}


		fst_ch 	 = pch [ 0 ];

		if  ( '1' ==  fst_ch   ) 
		{

			if ( NULL == (pch = strtok (NULL, " ,.")) ) 
			{ printf ("Err Nul in pch\n"); break ; }


//			printf ("%s\n", pch);

			if ( 0 != memcmp ("00000000000000000000", pch, 20))
			{
				memcpy ( str_G, pch, 20);
				str1 = 1;
			}
			
			else 
			{
//				printf ("%s\n", pch);
				str1 = 0;
				str2 = 0;
				continue;
			}
		}

//		if  ( '2' ==  fst_ch   ) 
//		{
//
//			if ( NULL == (pch = strtok (NULL, " ,.")) ) 
//			{ printf ("Err Nul in pch\n"); break ; }
//
//
//			if ( 0 != memcmp ("00000000000000000000", pch, 20))
//			{
////				strncpy ( str_E, pch, 20);
////				str2 = 1;
//			}
//			
//			else 
//			{
////				printf ("%s\n", pch);
//				str1 = 0;
//				str2 = 0;
//				continue;
//			}
//		}

		if  ( '2' ==  fst_ch   ) 
		{

			if ( NULL == (pch = strtok (NULL, " ,.")) ) 
			{ printf ("Err Nul in pch\n"); break ; }


			if ( 0 != memcmp ("00000000000000000000", pch, 20))
			{
				memcpy ( str_E, pch, 20);
				str2 = 1;
			}
			
			else 
			{
//				printf ("%s\n", pch);
				str1 = 0;
				str2 = 0;
				continue;
			}
		}


		if ( str1 && str2 )
		{
			
			str1 = 0;
			str2 = 0;

			++ readings ; 
			diff_bits = 0;
			FP_bits = 0; 
			FN_bits = 0;
			zeros = 0.0;
			ones  = 0.0;

			for ( i = 0; i < 20; i++  )
			{

				G = char_to_int ( str_G [ i ]  );
				E = char_to_int ( str_E [ i ]  );

//				printf ("%x:%x:%d\n", E, G, diff_bits );
				diff_bits += count_bits ( E ^ G );

				//////////////////////////////
				for ( k = 0; k < 4 ; k ++ )
				{
//					++ total_no_bits;
					G_bit = 0x01 & ( G >> k );
					E_bit = 0x01 & ( E >> k );


					switch ( G_bit )
					{
						case 1:
							++ ones;
							if ( 0 == E_bit )
								++ FN_bits;
							break;
						case 0:
							++ zeros;
							if ( 1 == E_bit )
								++ FP_bits;
							break ;
						default:
							printf ("Err 0s and 1s\n");
							goto out;

					}
				}

			}

//			if ( 0 != diff_bits )
			{


//FPR = FP / (FP+TN) = FP / all zeros
//FNR = FN / (FN+TP) = FN / all ones

				MSP_vec = diff_bits / 79.0 ;  

				if (0 == (zeros -1.0 ))
					FP_vec = 0.000;

				else	
					FP_vec = FP_bits /  (zeros - 1.0);

				if (0 == ones)
					FN_vec = 0.000;

				else	
					FN_vec = FN_bits /  ones;


				fprintf (f_out, "%f, %f, %f\n",  MSP_vec, FP_vec, FN_vec );

			}
			
		}

//	if ( 2 < readings ) 
//		break ;
	}
//////////////////////////
out:
	fclose (f_in);
	fclose (f_out);
	return 0;

}
///////////////////////////////////////////////////////////////////////
