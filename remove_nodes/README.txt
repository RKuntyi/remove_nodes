
General
-------------
This module was created like test task. Original scope:
You need to write a module to Drupal 7 that removes old nodes.
On the admin page should be able to select the type of content and time for each of the content types, how long this nodes need to save on the site.
Also, a field with an email to which a confirmation email will be sent for deletion.
Deletion should occur according to the following algorithm:
1. Once a day, an automatic letter is generated to the email specified in the admin panel with a list of all nodes that will be deleted.
2. Also in the letter, there should be a link when clicking on which all the content specified in the letter will be deleted.

Installation
------------

As regular Drupal module.

Automated Testing (SimpleTest)
---------------------------
Coder Sniffer comes with a SimpleTest test suite to make sure module work correctly.
To check enable Testing module from the Core:

drush en simpletest -y

Then go to the Testing module interface /admin/config/development/testing
Select Remove nodes module and Run tests.

Author
------
Roman Kuntyi
romankuntyilviv@gmail.com
