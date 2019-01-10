Savings Calculator
----------------------------

### Introduction

The Savings Calculator module provides savings-analysis and financial estimate
data for users wanting a solar estimate.  The savings data provided comes from 
the use of [Genability's](http://developer.genability.com/) API and data network.
Property square footage data comes the the use of [Zillows's](https://www.zillow.com/howto/api/APIOverview.htm) 
API service.

### Requirements

This module is not dependent on any other Drupal modules, but __does__ require 
developer/API accounts and credentials for Genability as well as Zillow.

### Installation

* Install as you would normally install a contributed Drupal module. Visit https://drupal.org/documentation/install/modules-themes/modules-7 
for further information.
* After the module has been installed, you must import the Savings Calculator rates and escalation values.  A [sql file](./data/sunrun_calculator_pricing.sql) with this data has been provided.
* Visit the module configuration page and add all of the required fields (api credentials, redirect url, etc).

### Configuration
You can access this module's admin configuration by browsing directly to https://www.sunrun.com/admin/sunrun/calculator 
or by going to Sunrun -> Solar Calculator Settings in the main menu.

* __Enable Caching__ - If enabled, analysis results will be cached based on a combination 
of the zipcode and monthly estimated payment.  All future requests with that combination will
receive a cached result, in turn resulting in a much faster response time.
* __Enable Database Logging__ - If enabled, all requests and responses to/from the
Savings Calculator service endpoint will be logged to the database table _sunrun_calculator_logging_.  __NOTE:__ This will eventually lead
to a large database table unless monitored and purged.

__Zillow Settings__

* __Host__ - URL to Zillow's API service
* __ZWS-ID__ - Access key required for Zillow's API service

__Genability Settings__

* __Host__ - URL to Genability's API service
* __Username__ - Username credential required for Genability's API service
* __Password__ - Password credential required for Genability's API service
* __API Error Redirect URL__ - URL the user is redirected to when an error or exception needs handling

### API Endpoints

Savings analysis data is provided through two endpoints created by this module.  A [POSTMAN collection](./data/Sunrun%20Savings%20Calculator.postman_collection.json)
has been provided to assist with request requirements.

__Savings Analysis__ - rest/v1/savings-analysis

Returns a Savings Analysis based on the zipcode and monthly estimated payment.  The returned analysis
also includes parameters required for making a Financial Estimate requires: `account_id` and `lse_id`.

Response:
```
{
    "status": "success|error",
    "account_id": "string",
    "lse_id": int,
    "trees_planted": int,
    "home_appreciation": float,
    "electricity_cost_lifetime": int,
    "system_size": float,    
    "monthly": {
        "upfront_cost": 0,
        "monthly_pmt": float,
        "lifetime_savings": int,
    },
    "buy": {
        "upfront_cost": int,
        "monthly_pmt": 0,
        "lifetime_savings": int,
    },
    "advantage": {
        "upfront_cost": int,
        "monthly_pmt": 0,
        "lifetime_savings": int,
    },
    "prepaid": {
        "upfront_cost": int,
        "monthly_pmt": 0,
        "lifetime_savings": int,
    },        
    "property_size": int
}
```

__Financial Estimate__ - rest/v1/financing-estimate

__NOTE:__ The `Financial Estimate` service request requires parameters that can only be
acquired by first submitting a `Savings Analysis` request.

Primary use is to provide an updated analysis that takes into account a new estimate monthly payment.

The only difference between this response and the `savings-analysis` response is that we omit
the property size.

```
{
    "status": "success|error",
    "account_id": "string",
    "lse_id": int,
    "trees_planted": int,
    "home_appreciation": float,
    "system_size": float,        
    "electricity_cost_lifetime": int,    
    "monthly": {
        "upfront_cost": 0,
        "monthly_pmt": float,
        "lifetime_savings": int,
    },
    "buy": {
        "upfront_cost": int,
        "monthly_pmt": 0,
        "lifetime_savings": int,
    },
    "advantage": {
        "upfront_cost": int,
        "monthly_pmt": 0,
        "lifetime_savings": int,
    },
    "prepaid": {
        "upfront_cost": int,
        "monthly_pmt": 0,
        "lifetime_savings": int,
    },    
}
```
