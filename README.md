
Nice courses:
--------------
- http://web.stanford.edu/class/ee360/resources.html
- https://courses.engr.illinois.edu/ece498rc3/
- https://github.com/bendrucker/columbia

Nice projects:
-----------
- http://cpslab.cs.mcgill.ca/#people
- http://people.csail.mit.edu/szym/rawofdm/README.html
- http://www.ccs-labs.org/software/gr-ieee802-11/
- http://www.asp.eurasipjournals.com/content/2011/1/135
- https://sites.google.com/a/vt.edu/amp_lab/projects/active-projects
- https://www.microsoft.com/en-us/research/project/microsoft-research-software-radio-sora/

Articles:
---------
- http://www.wireshark.ch/download/Sharkfest10_A10_WLAN-802-11n-MIMO-Analysis.pdf
- http://airmagnet.flukenetworks.com/assets/whitepaper/WP-802.11nPrimer.pdf
- http://www.cs.tut.fi/kurssit/TLT-6556/Slides/2-802.11n.pdf

Wireless Comm., mobile computing, MIMO, etc
-----------
- http://web.stanford.edu/class/ee360/resources.html

CAN
----
- https://github.com/linux-can/can-utils
- https://bitbucket.org/DataspeedInc/dataspeed_can
- candump ubuntu

Python
--------------
- https://docs.python.org/3/tutorial/index.html


Goog progects
-------------
- https://www.google.com/?gws_rd=ssl#q=google+project+soli

Error correction coding
-----
- https://courses.cs.washington.edu/courses/cse466/11au/calendar/11-ErrorControlCodes-posted3.pdf

Misc
----------
- [Human rights] (http://www.human-rights-in-islam.co.uk/index.php?option=com_content&view=article&id=184:congress-secularism-and-mumbais-season-of-arson-by-ghulam-muhammed&catid=35:political)
- [Al-Isla](https://www.al-islam.org/voice-human-justice-sautul-adalatil-insaniyah-george-jordac/ruler-one-people)

- https://www.yahosein.com/vb/showthread.php?t=131456
- http://www.yahosein.com/vb/showthread.php?t=131457
- http://ar.lib.eshia.ir/

RT Linux
-----
- https://rt.wiki.kernel.org/index.php/Frequently_Asked_Questions
- https://packages.debian.org/stretch/kernel/
- http://wiki.ros.org/melodic/Installation/Debian
- https://wiki.ubuntu.com/KernelTeam/GitKernelBuild
- https://linuxmusicians.com/viewtopic.php?f=19&t=18536
- https://wiki.ubuntu.com/RealTime


Tech repor CSE
----
- http://www.cse.msu.edu/publications/tech/TR/


PHP Practice
-----
- Laravel
- https://www.youtube.com/watch?v=xevIxUQ1SH4
- https://askubuntu.com/questions/925072/unable-to-execute-the-laravel-command-laravel-new-myapp
- https://getcomposer.org/download/
- https://code.visualstudio.com/docs/?dv=linux64_deb
- https://laravel.com/docs/7.x/installation
- https://stackoverflow.com/questions/33767605/new-laravel-project-in-netbeans
- https://computingforgeeks.com/how-to-install-java-14-on-ubuntu-debian/
- https://www.digitalocean.com/community/tutorials/how-to-install-and-configure-laravel-with-lemp-on-ubuntu-18-04

Software Design Pattrens
-----
- Question: Isn't MVC anti OOP?
- https://softwareengineering.stackexchange.com/questions/168316/isnt-mvc-anti-oop
- MVC works at a much higher level of abstraction than single objects, and in fact each of the three (model, view and controller) will typically consists of many objects that each have both data and behavior. That objects which encapsulate data and behavior are a good fundamental building block for programs in general doesn't mean it's the best pattern at all levels of abstraction and for all purposes.

- OOP does not restrict interactions among objects that each have their own data and their own behavior. Think of an ant and an ant colony analogy: behavior of an individual ant (run around all day, bringing food) is different from behavior of the overall colony (find the most desirable place, make more ants). The MVC pattern describes the desired social structure of an ant colony, while OOP guides the design of individual ants.

Database concepts
---
- Many2Many relations https://web.csulb.edu/colleges/coe/cecs/dbdesign/dbdesign.php?page=manymany.php

MySQL Workbench vs MariaDB
-----
- https://stackoverflow.com/questions/22616861/can-i-use-mysql-workbench-to-create-mariadb
- So my experiences are, yes you can use MySQL Workbench for MariaDB database designs.

However I needed to change the "Default Target MySQL Version" to 5.7.

This can be done by going to: Edit->Preferences in the menu. And finally to Modeling->MySQL.

Since the latest MySQL version, v8.x, the SQL statements are not compatible with MariaDB statements (like creating an index). MariabDB creating an index on a table:

INDEX `fk_rsg_sub_level_rsg_top_level1_idx` (`rgs_top_level_id` ASC)

vs

MySQL:

INDEX `fk_rsg_sub_level_rsg_top_level1_idx` (`rgs_top_level_id` ASC) VISIBLE

MariaDB can't handle this VISIBLE keyword in this example. Using an old MySQL Version, MySQL Workbench will forward engineer a compatible MariaDB SQL file.

Currently (Oct 2019) the generated SQL_MODE output is still compatible with MariaDB. Just like InnoDB, which is also preferred when using MariaDB in most cases.

Laravel
----
- What is URI?
URI stands for Uniform Resource Identifier. URI is a text which is used to identify any resource or name on Internet. URI has two specializations in the form of URL (Uniform Resource Locator) and URN (Uniform Resource Name) to identify resource and name. We mostly see examples of URL and URN in the real word. If you are working on JSP and familiar with using tag library e.g. display tag and JSTL core tag library, then you may remember the use of URI to locate binary corresponding to a tag library.

Read more: https://www.java67.com/2013/01/difference-between-url-uri-and-urn.html#ixzz6MFlF9ptZ

A URI (Uniform Resource Identifier) is a string that refers to a resource. The most common are URLs, which identify the resource by giving its location on the Web. URNs, by contrast, refer to a resource by a name, in a given namespace, such as the ISBN of a book.


- See: (https://developer.mozilla.org/en-US/docs/Learn/Common_questions/What_is_a_URL)
- What is URL?
URL standards for Uniform resource locator and it is a subset of URI or Uniform Resource Identifier. URL includes location as well as the protocol to retrieve the resource e.g. in http://java67.blogspot.sg/2012/09/what-is-new-in-java-7-top-5-jdk-7.html, HTTP is a protocol which can be used to retrieve resource what-is-new-in-java-7-top-5-jdk-7.html available in location http://java67.blogspot.com directory. It's not necessary that URL always include HTTP as protocol, it can use any protocol e.g. ftp://, https:// or ldap://.

The most common form of URI is the Uniform Resource Locator (URL), which is known as the web address.

Read more: https://www.java67.com/2013/01/difference-between-url-uri-and-urn.html#ixzz6MFkosq66
Read more: https://skorks.com/2010/05/what-every-developer-should-know-about-urls/
Read more: https://launchschool.com/books/http/read/what_is_a_url

- What is URN
URN stands for Uniform Resource Name. URN is also the subset of URI. One of the best examples of URN is ISBN number which is used to uniquely identify a book. URN is completely different than URL as it doesn't include any protocol.

Read more: https://www.java67.com/2013/01/difference-between-url-uri-and-urn.html#ixzz6MFlzCHDJ


- Query parameters: https://howto.caspio.com/parameters/parameters-as-query-string-values/
- HTTP Request: https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods

- HTTP
HTTP defines a set of request methods to indicate the desired action to be performed for a given resource. Although they can also be nouns, these request methods are sometimes referred to as HTTP verbs. Each of them implements a different semantic, but some common features are shared by a group of them: e.g. a request method can be safe, idempotent, or cacheable.


![Query Parameters](https://github.com/myreadings1/RDING/blob/master/img/creating_query_strings1.png)

View in Laravel
--
- Read here: https://laravel.com/docs/7.x/views
Views may also be nested within subdirectories of the resources/views directory. "Dot" notation may be used to reference nested views. For example, if your view is stored at resources/views/admin/profile.blade.php, you may reference it like so:

return view('admin.profile', $data);

- Problem: Laravel only loads the first index page and no other pages.
- Solution: 
$ sudo a2enmod rewrite
$ sudo service apache2 restart
Source: (https://askubuntu.com/questions/1012620/php-laravel-error-no-pages-are-found-except-index-page-in-laravel-deployed-on-l)

Multiple role-based authentication in Laravel
----
- See (https://dev.to/kaperskyguru/multiple-role-based-authentication-in-laravel-30pc)

Installing composer
----
- See (https://www.digitalocean.com/community/tutorials/how-to-install-and-use-composer-on-ubuntu-18-04)

Deploy Laravel on server
-----
- See (https://dev.to/asapabedi/deploying-laravel-5-applications-on-shared-hosting-without-the-use-of-ssh--16a6)
- 1) Upload compressed file of the project, like drcharity3.zip.
- 2) unzil the file outside the public_html folder (server).
- 3) Move files in the public folder (Laravel) to the public_html folder (server). Other Larval project's file should be placed in some folder outside public_html. Example, we use a folder called (drcharity3).
- 4) Edit index.php in the public_html (server) and change two lines as follows:
.. 
//require __DIR__.'/../vendor/autoload.php';
require __DIR__.'/../drcharity3/vendor/autoload.php';
..
//$app = require_once __DIR__.'/../bootstrap/app.php';
$app = require_once __DIR__.'/../drcharity3/bootstrap/app.php';

- 5) On the server side, create a DB, then get (DB_Name, DB_Username, DB_Pass).
- 6) On the server side, create a (.env) file, copy and paste content from (.env) file in your Laravel project; 
- 7) Edit two files (.env) and config/database.php and change DB access parameters as shown in point (5) above.
.. the database.php should looks like:
          //'database' => env('DB_Name', 'forge'),
            'database' => env('DB_Name','DB_Name'),
            //'username' => env('DB_Username', 'forge'),
            'username' => env('DB_Username','DB_Username'),
            'password' => env('DB_Pass', 'DB_Pass'),

- 8) You should be good to go!


Laravel on local server
------
- See (https://tecadmin.net/install-laravel-on-debian-9-stretch/)
- See (https://stackoverflow.com/questions/31435283/laravel-5-only-root-route-works)..
- Enable apache2 rewrite module:
- sudo a2enmod rewrite
- Then restart the apache2 server: sudo service apache2 restart
-And make sure that AllowOverride All to your apache2 config file.


RPI4 update
-----
- See (https://www.raspberrypi.org/documentation/hardware/raspberrypi/booteeprom.md)

TCPDF + Laravel
-----
- See (https://ourcodeworld.com/articles/read/233/how-to-generate-a-pdf-from-html-with-tcpdf-in-laravel)

TCPDF ADD NEW FONT
--------------
- See (https://ourcodeworld.com/articles/read/601/how-to-implement-custom-fonts-in-tcpdf)
- See (TCPDF_ADD_NEW_FONT.pdf)

Static and Fallback IP address
--------------
- See (https://wiki.archlinux.org/index.php/Dhcpcd#Fallback_static_profile)

Install LAMP
-----------
- Install phpmyadmin (sudo apt install phpmyadmin)

HTML Date
-----
- See (https://stackoverflow.com/questions/6982692/how-to-set-input-type-dates-default-value-to-today)
this works for me:

document.getElementById('datePicker').valueAsDate = new Date();

https://developer.mozilla.org/en-US/docs/Web/API/HTMLInputElement

Group of checkboxed Laravel
-----
- See (https://laracasts.com/discuss/channels/laravel/how-can-i-delete-users-by-chosing-them-with-checkboxes)

In array check
----
- See ()
$design_id = 'hc1wXBL7zCsdfMu';
$list_desings_ids = array('hc1wXBL7zCsdfMu','dhdsfHddfD','otheridshere');

if(in_array($design_id, $list_desings_ids))
{
  echo "Yes, design_id: $design_id exits in array";

}

Popup Model Laravel
----
- See (https://medium.com/techiediaries-com/laravel-7-crud-tutorial-build-a-crud-app-with-mysql-and-bootstrap-4-4ed8e94f2db0)

Git 
--
- clone local repo
git clone C:\folder1 folder2

-Branches:
git checkout -b iss53
Switched to a new branch "iss53"

This is shorthand for:

$ git branch iss53
$ git checkout iss53

Enable bootstrap
---
- See (https://www.positronx.io/how-to-properly-install-and-use-bootstrap-in-laravel/)

Enable Bootstrap 4 RTL
-----
- See bootstrap file here ()

Probability Books
----
- See this webside (https://github.com/manjunath5496/Probability-Books)

Change raspberry pi pass 
--
- sudo passwd root

TP-Link 8 Linux Driver
---
- See (https://github.com/Mange/rtl8192eu-linux-driver)
- See (https://raspberrypi.stackexchange.com/questions/111359/how-to-install-tp-link-tl-wn823n-v2-on-rasperry-pi-2)

axios normal request
----
- See (https://blog.bitsrc.io/requests-in-vuejs-fetch-api-and-axios-a-comparison-a0c13f241888)
- See (https://gist.github.com/javilobo8/097c30a233786be52070986d8cdb1743)


MariaDB allow remote connections
---
- Command (sudo nano 50-server.cnf ) on raspberry pi
- See (https://webdock.io/en/docs/how-guides/how-enable-remote-access-your-mariadbmysql-database)

Math readings:
---
- https://www.math.utah.edu/online/1010/radicals/
- https://math.libretexts.org/Bookshelves/Algebra/Book%3A_Beginning_Algebra_(Redden)/01%3A_Real_Numbers_and_Their_Operations/1.06%3A_Exponents_and_Square_Roots
- https://tutorial.math.lamar.edu/Classes/Alg/Radicals.aspx
- https://www.mathsisfun.com/definitions/index-power-.html
- http://www.amsi.org.au/teacher_modules/Rhombuses_Kites_and_Trapezia.html
- http://www.math.niu.edu/~richard/Math101/logic.pdf
- https://www.math.toronto.edu/preparing-for-calculus/3_logic/we_2_if_then.html
- http://www.math.niu.edu/~richard/Math101/implies.pdf
- https://faculty.math.illinois.edu/~vddries/main.pdf

Laravel search nested relation tables
----
- See (https://stackoverflow.com/questions/53278823/laravel-how-to-use-where-clause-on-both-parent-and-child-model-in-one-to-many-r)

Filter query results
---
- See (https://stackoverflow.com/questions/31657851/filtering-laravel-eloquent-collections-with-filter-method)
- See (https://laraveldaily.com/filtering-query-results-with-different-conditions-on-the-same-page/)

Q&A stackoverflow
---
- See (https://stackoverflow.com/questions/64684677/laravel-searching-relationships-with-conditions-and-retrieving-the-records)

Components with Vuejs
---
- See (https://stackoverflow.com/questions/51225378/how-to-watch-child-properties-changes-from-parent-component)
- See explanation (https://dev.to/rolanddoda/8-secrets-vue-developers-must-know-5la)
- See code (https://codesandbox.io/s/yk1l5zp9l9?file=/src/App.vue:121-152)

Sharing data between components
--
- See (https://www.smashingmagazine.com/2020/01/data-components-vue-js/)
- See (https://stackoverflow.com/questions/48954191/how-can-i-access-child-component-data-from-a-parent-in-vue)

شعر امير المؤمنين
--
- http://www.elibrary4arab.com/viewtopic.php?f=6&t=420
- 80211 reciver based on RF funnel. reuse the same channel and save bandwidth. 
- many ideas are there about multiple receivers
- book about prob. with a better description. ;)
- Is there any system that keeps analog signal in a circuit for a while? how to benefit from this capability?
- Multi-standard receiver, like BT, Wi, Zig, GSM ... This radio is based on RF-Funn
