# SmartyStreets for Drupal 8

This module integrates with the 
[SmartyStreets API](http://smartystreets.com), 
allowing for postal address lookup and verification.

## Settings

To configure this module and add your SmartyStreets API 
credentials, go here: `/admin/config/services/smartystreets`

*Note:* To generate a secret key pair, visit 
[SmartyStreets Authentication](http://smartystreets.com/docs/authentication).

## Use

After configuring this module, you'll be able to take advantage of 
three SmartyStreets APIs: US Street Address API, US ZIP Code API and 
US Autocomplete API.

To call the SmartyStreets service in another module, first include 
the following code.
```
$smartystreets = \Drupal::service('smartysteets.address_lookup');
```

Below are examples for using each API. 
To learn more about them, check out the 
[SmartyStreets documentation](https://smartystreets.com/docs).

### US Street Address API
After performing a US Street Address lookup, you have the option of 
generating a hash from the results.
```
$results = $smartystreets->USStreetAddress('820 high street, worthington, ohio 43085');
$hash = $smartystreets->generateHash($results);
```

### US ZIP Code API
```
$results = $smartystreets->USZipCode('worthington', 'ohio', '43085');
```

### US Autocomplete API
```
$results = $smartystreets->USAutocomplete('820 high');
```

## What's changed since Drupal 7?

### New
**Additional API calls:** The Drupal 7 version of this module 
focused on the US Street Address API. Now, you can use the 
US ZIP Code API and US Autocomplete API as well.

**More configuration options:** Fairly recently, SmartyStreets 
started to require both an Auth ID and Auth Token for 
authentication. It also changed the hostname used to make API 
calls, which was originally hardcoded into the module 
([Issue #2678216](https://www.drupal.org/node/2678216)). 
In case that happens again, the module's configuration page 
now provides fields for changing the hostname, plus a place 
for entering both authentication credentials.

### Gone
**LiveAddress API with Javascript:** The Drupal 7 version of the 
module included an experimental Javascript file that could be used 
to make API calls. However, this 
[script is no longer supported by SmartyStreets](https://smartystreets.com/archive/javascript), 
as it uses the outdated LiveAddres API (rather than the current 
US Street Address API). At this time, an updated alternative 
doesn't appear to be provided by SmartyStreets.
