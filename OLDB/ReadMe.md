
OL8.5 Installation
-----


ODB Installation Steps
----
Prerequisites and dependencies
1- Dependencies 


```ruby
yum install -y oracle-database-preinstall-19c
```

Start Listener
---

Start Oracle Database
---
1- Open Linux teminal to login to SQLPlus database (i.e. the Oracle Database), and type the following in the command line:

```ruby
sqlplus "/ AS SYSDBA"
```

Images
----
![This is an image](https://myoctocat.com/assets/images/base-octocat.svg)


Stop Listener

Linux Sys Config
---
1- Creating an Oracle home directory
mkdir -p /u01/app/oracle/product/19.3/db_home
chown -R oracle:oinstall /u01
chmod -R 775 /u01



Start ODB
----
- 1)

Stop ODB
----
- 2)


Network Connections
----
- Listener
- tnsnames

Go vs APS.Net Core Comparison
-----
- See the comparision (https://medium.com/hackernoon/go-vs-net-core-in-terms-of-http-performance-7535a61b67b8)
- 
