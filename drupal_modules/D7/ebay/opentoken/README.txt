This module lets eBay users log in using Opentoken SSO.


INSTALLATION

1) Contact SSO team (DL-eBay-GET-SSO-Integrations@ebay.com) and get agent-config.txt file and SSO URL for your application.
2) Place this module in sites/all/modules/custom folder of your Drupal installation.
3) Go to user/login. Log in as super-admin into Drupal (uid = 1).
3) Go to admin/modules and enable opentoken module.
4) Go to admin/config/system/opentoken. In the form, paste the content of the agent-config.txt file and the SSO URL. Read description of each field in the form to ensure that the content is entered in correct format.


USE

All anonymous users will be directed to Opentoken pingidentity server for authentication. Once they are authorized, they will be redirected back to the site.

For logging in as uid 1, go to /user/admin-login.
