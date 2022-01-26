Oracle Linux 8.5 Operating System Installation
-----


Oracle Database 19c Installation Steps
----

Prerequisites and dependencies
----

- Installing dependencies 


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
![Tis is an image]( https://github.com/myreadings1/RDING/blob/master/OLDB/imgs/dependencies_install.png )


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
