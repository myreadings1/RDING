Oracle Linux 8.5 Operating System Installation
-----
- Coming soon ...

[Contribution guidelines for this project](docs/CONTRIBUTING.md)


Oracle Database 19c Installation Steps
----


```ruby
cd $ORACLE_HOME
unzip -qo /home/oracle/Downloads/LINUX.X64_193000_db_home.zip
```


```ruby
cd $ORACLE_HOME
```

```ruby
#For GUI installation
./runInstaller

```

Prerequisites and dependencies
----

- Installing dependencies 


```ruby
yum install -y oracle-database-preinstall-19c
```


Installing the database commands:
---


```ruby
cd $ORACLE_HOME
unzip -qo /home/oracle/Downloads/LINUX.X64_193000_db_home.zip
```

Operating System Configuration 
---
1- Creating an Oracle home directory

```ruby
mkdir -p /u01/app/oracle/product/19.3/db_home
chown -R oracle:oinstall /u01
chmod -R 775 /u01
```


2- Bash configuration

Open a new terminal and type the following command:

```ruby
vi .bash_profile
```

```ruby
# .bash_profile
# Get the aliases and functions

if [ -f ~/.bashrc ]; then
	. ~/.bashrc
fi

# User specific environment and startup programs

export ORACLE_BASE=/u01/app/oracle
export ORACLE_HOME=/u01/app/oracle/product/19.3/db_home
export ORACLE_SID=CDB
export LD_LIBRARY_PATH=\$ORACLE_HOME/lib:/lib:/usr/lib
export CLASSPATH=\$ORACLE_HOME/jlib:\$ORACLE_HOME/rdbms/jlib
export NLS_LANG=american_america.al32utf8
export NLS_DATE_FORMAT="yyyy-mm-dd:hh24:mi:ss"

PATH=$PATH:$HOME/.local/bin:$ORACLE_HOME/bin

export PATH

```
- The bash file should look like as follow:

![This is an image]( https://github.com/myreadings1/RDING/blob/master/OLDB/imgs/bash_config.png )

- Open a new terminal and type the following command:

```ruby
. .bash_profile
```

- The terminal should look like as follow:

![This is an image]( https://github.com/myreadings1/RDING/blob/master/OLDB/imgs/bash_config_done.png )


Start Listener
---
 
Start Oracle Database
---
1- Open Linux teminal to Login to SQLPlus database (i.e. the Oracle Database), and type the following in the command line:

```ruby
sqlplus "/ AS SYSDBA"
```

```ruby
STARTUP FORCE;
```

- Run the command below to open-up our container database.

```ruby
ALTER PLUGGABLE DATABASE ALL OPEN;
```

- Run the command below to connect to ORCLPDB.

```ruby
ALTER SESSION SET container=ORCLPDB;
```




Images
----
![This is an image]( https://github.com/myreadings1/RDING/blob/master/OLDB/imgs/dependencies_install.png )

![This is an image]( https://github.com/myreadings1/RDING/blob/master/OLDB/imgs/ODB_Folder_Creation.png )

![This is an image]( https://github.com/myreadings1/RDING/blob/master/OLDB/imgs/ODB_folder.png )


The Listener
---


```ruby
lsnrctl stop
lsnrctl start
lsnrctl status
```

6. Unlock HR schema

Finally, we can unlock the HR schema with the command below.


```ruby
ALTER USER HR IDENTIFIED BY HR ACCOUNT UNLOCK;
```


Start Oracle Database
----
- Open a new terminal and type the following command:


Stop ODB
----
- Shutdown database

```ruby
shutdown normal;
```

```ruby
shutdown abort;
```

Network Connections
----
- Listener
- tnsnames

7. Checking the tnsnames.ora configuration

```ruby
cd $ORACLE_HOME/bin
./tnsping pdb1
```

![This is an image]( https://github.com/myreadings1/RDING/blob/master/OLDB/imgs/chk_tnsping.png )

Finalize the HR dataset connection
---
- On termial, run the following command

```ruby
@?/demo/schema/human_resources/hr_main.sql 
```

- Follow the prompts on the screen. Use the criteria below to guide you.
 -- Enter hr here. This is for the user HR. This is what we will use to access the database.
 -- Enter an appropriate tablespace, for example, users as the default tablespace for HR.
 -- Enter temp as the temporary tablespace for HR
 -- Enter the directory path for your log directory, for example:



```ruby
$ORACLE_HOME/demo/schema/log/
```

- Now we can send quieries to the HR database


```ruby
SELECT table_name FROM user_tables;
```
The SQL query result should look as follow:

![This is an image]( https://github.com/myreadings1/RDING/blob/master/OLDB/imgs/hr_db_query_response.png )


Accessing a sample dataset
---
1- Log-in to SQL Plus as a SYS user



```ruby
sqlplus "/ AS SYSDBA"
```

2- Find PDB name: Execute the following command in SQL

```ruby
SELECT name, con_id, open_mode FROM v$pdbs;
```

![This is an image]( https://github.com/myreadings1/RDING/blob/master/OLDB/imgs/find_DB_name.png )



Starting the database after a computer reboot
---
1- First, start the listener with the command below

```ruby
lsnrctl start
```
2- Run the following commands to startup the database.

```ruby
sqlplus "/ AS SYSDBA"
STARTUP FORCE;
ALTER PLUGGABLE DATABASE ALL OPEN;
ALTER SESSION SET container=PDB1;

```

 
