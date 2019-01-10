<!--Nathan Code Start-->

<div class="student-landing-page">
<!--    <div class="header-block">-->
<!--        <svg class="svg" xmlns="http://www.w3.org/2000/svg" width="261.406" height="31" viewBox="0 0 261.406 31">-->
<!--            <path d="M469,1208h58.953c64.047,0,60.953,30,72,30s8.047-30,71.012-30H729v-1H469v1Z" transform="translate(-468.906 -1207)"></path>-->
<!--        </svg>-->
<!--        <div class="container">-->
<!--            <div class="row">-->
<!--                <div class="col-xs-12">-->
<!--                    <h1 class="welcome-title">Welcome to Reading Central</h1>-->
<!--                </div>-->
<!--            </div>-->
<!--        </div>-->
<!--    </div>-->
    <div class="sign-in-container">
        <div class="sign-in">
            <div class="row">
                <div class="col-sm-12 col-md-offset-6 col-md-6">
                    <h3 class="sign-in-header-txt">Sign in with information provided to you by teacher or parent:</h3>
                    <div class="sign-in-form">
                        <?php print $sign_in_form; ?>
                    </div>
                    <p class="footer-user-pwd-txt">Forget your username or password? Contact your parent or teacher.</p>
                </div>
            </div>
        </div>
    </div>
</div>

<!--Nathan Code End-->

<?php if ($page['sub_footer']) : ?>
    <?php print render($page['sub_footer']); ?>
<?php endif; ?>