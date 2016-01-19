  var timerId = null, timeout = 5;
  function WaitUntilCustomerGUIDIsRetrieved() {
    if (!!(timerId)) {
      if (timeout == 0) {
        return;
      }
      if (typeof this.GetElqCustomerGUID === 'function') {
        if (typeof(document.forms["eloqua_form"] !== 'undefined')) {
          document.forms["eloqua_form"].elements["submitted[elqcustomerguid]"].value = GetElqCustomerGUID();
        }
        return;
      }
      timeout -= 1;
    }
    timerId = setTimeout("WaitUntilCustomerGUIDIsRetrieved()", 500);
    return;
  }
  window.onload = WaitUntilCustomerGUIDIsRetrieved;
  _elqQ.push(['elqGetCustomerGUID']);