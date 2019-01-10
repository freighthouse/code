<div class="rif-banner" style="position:relative; top:0;">

    <div class="container-fluid">

        <div class="container">

            <nav class="navbar">
                <div class="container-fluid">
                    <div class="navbar-header">
                        <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#rif-navigation" aria-expanded="false">
                            <span class="sr-only">Toggle navigation</span>
                            <span class="icon-bar"></span>
                            <span class="icon-bar"></span>
                            <span class="icon-bar"></span>
                        </button>
                        <div class="btn-group visible-xs visible-sm top-mobile-button-group" role="group">
                            <?php if (!user_is_anonymous()){ ?><a href="https://secure.rif.org/page/6795/donate/1?&amp;s_src=literacy_central" class="btn btn-yellow student-hide">Donate</a>
                            <?php } ?>
                        </div>
                        <div class="logo-wrapper logo-wrapper-ln">
                            <a href="/" class="logo-rif-link"><img class="logo-rif" src="/sites/all/themes/custom/rif2018/build/img/logo-rif-lg.png" alt="RIF.org" /></a>
                            <img class="logo-divider" src="/sites/all/themes/custom/rif2018/build/img/logo-rif-divider.png" alt=" | " />
                            <a href="/literacy-network" class="logo-rif-ln-link"><img class="logo-ln" src="/sites/all/themes/custom/rif2018/build/img/logo-rif-literacy-central.png" alt="Literacy Central" /></a>
                        </div>
                    </div>
                  <?php if($username){ ?>
                      <div class="no-collapse">
                          <ul class="nav navbar-nav" style="padding-right: 30px;">
                              <li class="first last leaf"><a href="/literacy-tracker/student/dashboard" style="padding: 17px 0;"><?php print $username; ?></a></li>
                              <li>
                                  <div class="btn-group hidden-xs hidden-sm" role="group">
                                      <a href="/user/logout?destination=/literacy-tracker/student/sign-in" class="btn btn-yellow">Sign Out</a>
                                  </div>
                              </li>
                          </ul>
                      </div>

                      <div class="collapse navbar-collapse" id="rif-navigation">
                          <ul class="nav navbar-nav navbar-right">
                              <li class="first last leaf"><a href="/literacy-tracker/student/dashboard"><?php print $username; ?></a></li>
                          </ul>
                          <ul class="nav navbar-nav navbar-right sub-nav">
                              <li class="last leaf"><a href="/user/logout?destination=literacy-central/parents">Sign Out</a></li>
                          </ul>
                          <p class="navbar-text">
                              Welcome, <?php print $username; ?>
                          </p>

                      </div>
                  <?php } ?>
                </div>

            </nav>

        </div>

    </div>

</div>