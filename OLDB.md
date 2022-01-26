Oracle Linux 8.5 Operating System Installation
-----
- Coming soon ...

Oracle Database 19c Installation Steps
----

Prerequisites and dependencies
----

- Installing dependencies 


```ruby
yum install -y oracle-database-preinstall-19c
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

Images
----
![This is an image]( https://github.com/myreadings1/RDING/blob/master/OLDB/imgs/dependencies_install.png )


![This is an image]( https://github.com/myreadings1/RDING/blob/master/OLDB/imgs/ODB_Folder_Creation.png )
Stop Listener

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
