function prepop_display_name(){
    var username = document.getElementById('edit-name'),
    displayname = document.getElementById('edit-profile-display-name');

    if(displayname.value=="" && !isEmail(username.value)) {
        displayname.value = username.value;
    };

}

function isEmail(strEmail){
    validRegExp = /^[^@]+@[^@]+.[a-z]{2,}$/i;
    // search email text for regular exp matches
    if (strEmail.search(validRegExp) == -1) {
        return false;
    }
    return true;
}
        
if (Drupal.jsEnabled) {
    $(document).ready(
        function() {
            $("#edit-name").blur(
                function(){
                    prepop_display_name();
                }
            );
        }
    );
}
  
    
