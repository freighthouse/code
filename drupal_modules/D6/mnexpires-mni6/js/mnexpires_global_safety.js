var mnexpires_ge_zebra = true;
function mnexpires_globalfs_click() {
    if(mnexpires_ge_zebra) {
        alert(
            "WARNING: Changing the Global Expiration period should not " +
            "be done unless absolutely necessary. This is very dangerous. " +
            "Please do so with caution."
        );
    }
    mnexpires_ge_zebra = !mnexpires_ge_zebra;
}

function mnexpires_submit_confirm() {
    if(confirm(
        "Are you sure these expiration values are correct? " +
        "Once activated, nodes will be deleted, which cannot be undone."
    )) {
        return true; }
    return false;
}

jQuery(document).ready(
    function(){
        $("form#mnexpires-admin fieldset legend:contains('Global Expiration') a")
        .click(mnexpires_globalfs_click);
        $("form#mnexpires-admin input.form-submit")
        .click(mnexpires_submit_confirm);
    }
);