<?php
/**
 * @file
 * Template file for "get started" page on devl.apigee.com
 *
 * Incoming vars:
 * $name => name of user
 * $is_authenticated => bool
 *
 * Javascript on this page should ping the URL 'get-started/ajax' every 5 seconds
 * until it returns { "book_created": true }, then it should add content below step
 * three indicating success.  Subsequently it should stop pinging.  Such pinging
 * shouldn't even start if $is_authenticated == FALSE.
 */
?>
<div class="<?php print ($is_authenticated ? 'authenticated-user' : 'anonymous-user'); ?>">
  <h1 class="title">Welcome! <strong>Let’s get you started.</strong></h1>
  <p class="border-btm">Create your first Apigee app in minutes with the simple
  example below. Then dive into our tutorials, SDKs, and documentation.</p>
  <div>
    <?php if ($is_authenticated): ?>
      <h2>Thanks for signing up, <?php print check_plain($name); ?>.</h2>
      <p><em>Let’s get you started with app services.</em></p>
      <div class="well">
        <p>Next, download one or more of our SDKs, try the tutorial below, or go straight to the <a href="https://apigee.com/appservices/" target="_blank">admin portal</a>.
          If you are ready for more in-depth information, check out our <a href="http://apigee.com/docs/app-services" target="_blank">documentation</a>.
          <a href="https://apigee.com/appservices/#<?php print $_SESSION['usergrid']['name']; ?>/sandbox/dashboard" target="_blank" class="red-btn">Skip this tutorial</a></p>
      </div>
    <?php else: ?>
      <h2>Create your Apigee account</h2>
      <p><em>Don’t worry, once you complete this step, we’ll bring you back here.</em></p>
      <div class="well">
        <div class="btn-txt">
          <a class="btn" href="<?php print apigee_devl_get_started_signup_link(); ?>">Sign Up<br><span class="btn-btm">Free for Developers</span></a>
        </div>
      </div>
    <?php endif; ?>

  </div>
  <div>
    <h2>Download our SDK and examples apps for your language of choice</h2>
    <div class="well sdk-icons">
      <ul class="sdk-menu">
        <li class="first active"><a class="javascript" href="#javascript"></a></li>
        <li><a class="ios" href="#ios"></a></li>
        <li><a class="android" href="#android"></a></li>
        <li><a class="curl" href="#curl"></a></li>
        <li><a class="ruby" href="#ruby"></a></li>
        <li><a class="rails" href="#rails"></a></li>
        <li><a class="node" href="#node"></a></li>
        <li class="last"><a class="dotnet last" href="#dotnet"></a></li>
      </ul>
    </div>
    <p class="border-btm"><em>After downloading the SDK, navigate to <em>/new-project-template</em> and
      follow the steps below to add your App Services account details to the template app. The template app
      will create your first App Services data entities.</em></p>
  </div>
  <!-- JavaScript -->
  <div id="javascript" class="sdk-content">
    <div class="btn-txt sdk-button javascript">
      <a class="btn" href="http://www.apigee.com/docs/content/javascript-sdk-redirect" onmousedown="_gaq.push(['_trackEvent', 'SDK', 'Download', 'JavaScript']);" style="font-size: 16px;">Download SDK &amp; Example<br><span class="btn-btm">HTML5</span></a>
    </div>
    <dl>
      <span class="step step-one"></span>
      <dt><h2>Set your account details in the app</h2></dt>
      <dd>
        Extract the zip file and open <em>/new-project-template/index.html</em> in a text editor (Notepad, TextMate, SublimeText, or your preferred IDE). On line 18, enter your orgName — <?php if ($is_authenticated): ?><?php print $_SESSION['usergrid']['name']; ?> is<?php else: ?>it's<?php endif; ?> the username you picked when you signed up at <a href="http://apigee.com/about">apigee.com</a>. Keep the appName as “sandbox”: it’s a context we automatically created for you. It’s completely open by default, but don’t worry, other apps you create are not!
  <pre class="prettyprint linenums:16 lang-java"><code>
    var client = new Usergrid.Client({
        orgName:'YOUR APIGEE.COM USERNAME',
        appName:'sandbox'
    });
  </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-two"></span>
      <dt><h2>Set some details for your first object</h2></dt>
      <dd>
        On line 34, replace “the old man and the sea” with the title of your favorite book. Keep the type property on line 33 as “book”, otherwise we won’t know you completed the example!
  <pre class="prettyprint linenums:31 lang-java"><code>
    var options = {
        type:'book',
        title:'the old man and the sea'
    };
  </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-three"></span>
      <dt><h2>Now, run it!</h2></dt>
      <dd>
        You’re good to go! Open index.html in a web browser to see it running! This app will NOT work in Internet Explorer due to its lack of CORS support. Please use Firefox, Chrome or Safari instead.
      </dd>
    </dl>
  </div>

  <!-- iOS -->
  <div id="ios" class="sdk-content">
    <div class="btn-txt sdk-button ios">
      <a class="btn" href="http://www.apigee.com/docs/content/ios-sdk-redirect" onmousedown="_gaq.push(['_trackEvent', 'SDK', 'Download', 'iOS']);" style="font-size: 16px;">Download SDK &amp; Example<br><span class="btn-btm">iOS</span></a>
    </div>
    <dl>
      <span class="step step-one"></span>
      <dt><h2>Set your account details in the app</h2></dt>
      <dd>
        Extract the zip file and open <em>/new-project-template/Apigee App Services iOS Template.xcodeproj</em> in XCode (see instructions in the README.txt file if necessary). Look for the file Client.m (under the iOS Template folder). On line 30, enter your ORGNAME — it’s the username you picked when you signed up at <a href="http://apigee.com/about">apigee.com</a>. Keep the APPNAME as “sandbox”: it’s a context we automatically created for you. It’s completely open by default, but don’t worry, other apps you create are not!
  <pre class="prettyprint linenums:29 lang-java"><code>
      NSString * orgName = @"YOUR APIGEE.COM USERNAME";
      NSString * appName = @"sandbox";

      ApigeeClient *apigeeClient = [[ApigeeClient alloc]initWithOrganizationId: orgName
                                                   applicationID: appName];

      dataClient = [apigeeClient dataClient];
      [dataClient setLogging:true]; //comment to remove debug output from the console window
  </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-two"></span>
      <dt><h2>Set some details for your first object</h2></dt>
      <dd>
        On line 57, replace “the old man and the sea” with the title of your favorite book. Keep the type property on line 56 as “book”, otherwise we won’t know you completed the example!
  <pre class="prettyprint linenums:53 lang-java"><code>
    NSMutableDictionary *entity = [[NSMutableDictionary alloc] init ];

    [entity setObject:@"book" forKey:@"type"];
    [entity setObject:@"the old man and the sea" forKey:@"title"];

    ApigeeClientResponse *response = [dataClient createEntity:entity];
  </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-three"></span>
      <dt><h2>Now, run it!</h2></dt>
      <dd>
        You’re good to go! Just hit run and see if the example completes!
      </dd>
    </dl>
  </div>

  <!-- Android -->
  <div id="android" class="sdk-content">
    <div class="btn-txt sdk-button android">
      <a class="btn" href="http://www.apigee.com/docs/content/android-sdk-redirect" onmousedown="_gaq.push(['_trackEvent', 'SDK', 'Download', 'Android']);" style="font-size: 16px;">Download SDK &amp; Example<br><span class="btn-btm">Android</span></a>
    </div>
    <dl>
      <span class="step step-one"></span>
      <dt><h2>Set your account details in the app</h2></dt>
      <dd>
        Extract the zip file and import the project into Eclipse (see instructions in the README.txt file if necessary). On line 30, enter your ORGNAME — it’s the username you picked when you signed up at <a href="http://apigee.com/about">apigee.com</a>. Keep the APPNAME as “sandbox”: it’s a context we automatically created for you. It’s completely open by default, but don’t worry, other apps you create are not!
  <pre class="prettyprint linenums:29 lang-java"><code>
    String ORGNAME = "YOUR APIGEE.COM USERNAME";
    String APPNAME = "sandbox";

    ApigeeClient apigeeClient = new ApigeeClient(ORGNAME,APPNAME,this.getBaseContext());
    DataClient client = apigeeClient.getDataClient();
  </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-two"></span>
      <dt><h2>Set some details for your first object</h2></dt>
      <dd>
        On line 48, replace “the old man and the sea” with the title of your favorite book. Keep the type property on line 47 as “book”, otherwise we won’t know you completed the example!
  <pre class="prettyprint linenums:45 lang-java"><code>
    Map<String, Object> data = new HashMap<String, Object>();
    data.put("type", "book");
    data.put("title", "the old man and the sea");
  </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-three"></span>
      <dt><h2>Now, run it!</h2></dt>
      <dd>
        You’re good to go! Just Run the code to your preferred device or emulator.
      </dd>
    </dl>
  </div>

  <!-- Curl -->
  <div id="curl" class="sdk-content">
    <div class="btn-txt sdk-button curl">
      <a class="btn" href="https://github.com/apigee/appservices-rest-template/archive/apigee.zip" onmousedown="_gaq.push(['_trackEvent', 'SDK', 'Download', 'REST']);" target="_blank" style="font-size: 16px;">Download SDK &amp; Example<br><span class="btn-btm">Curl</span></a>
    </div>
    <dl>
      <span class="step step-one"></span>
      <dt><h2>Set your account details in the app</h2></dt>
      <dd>
        Extract the zip file and open curl_example.sh in a text editor (Notepad, TextMate, SublimeText, or your preferred IDE). On line 10, enter your ORGNAME — it’s the username you picked when you signed up at <a href="http://apigee.com/about">apigee.com</a>. Keep the APPNAME as “sandbox”: it’s a context we automatically created for you. It’s completely open by default, but don’t worry, other apps you create are not!
  <pre class="prettyprint linenums:9 lang-java"><code>
    ORGNAME="YOUR APIGEE.COM USERNAME"
    APPNAME="sandbox"
  </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-two"></span>
      <dt><h2>Set some details for your first object</h2></dt>
      <dd>
        On line 34 of <strong>curl_example.sh</strong>, replace your_title with the title of your favorite book. Keep the type as “book” otherwise we won’t know if you completed this step!
  <pre class="prettyprint linenums:21 lang-java"><code>
    TYPE="books"

    output=$(curl   -s \
      -X POST \
      -d '{ "title" : "the old man and the sea" }' \
      "https://api.usergrid.com/$ORGNAME/$APPNAME/$TYPE")
  </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-three"></span>
      <dt><h2>Now, run it!</h2></dt>
      <dd>
        You’re good to go! Open a terminal, navigate to this directory and execute the script:<pre>./curl_example.sh</pre>
        You may need to execute the following command before you run the script:<pre>chmod u+x curl_example.sh</pre>
      </dd>
    </dl>
  </div>

  <!-- Ruby -->
  <div id="ruby" class="sdk-content">
    <div class="btn-txt sdk-button ruby">
      <a class="btn" href="https://github.com/apigee/appservices-ruby-template/archive/apigee.zip" onmousedown="_gaq.push(['_trackEvent', 'SDK', 'Download', 'Ruby']);" target="_blank" style="font-size: 16px;">Download SDK &amp; Example<br><span class="btn-btm">Ruby</span></a>
    </div>
    <dl>
      <span class="step step-one"></span>
      <dt><h2>Set your account details in the app</h2></dt>
      <dd>
   Extract the zip file and install the gem by opening a terminal window, navigating to this directory and entering:
  <strong>bundle install</strong>.
  Next open ruby_example.rb in a text editor (Notepad, TextMate, SublimeText, or your preferred IDE). On line 10, enter your "organization" — it’s the username you picked when you signed up at <a href="http://apigee.com/about">apigee.com</a>. Keep the "application" set as “sandbox”: it’s a context we automatically created for you. It’s completely open by default, but don’t worry, other apps you create are not!
  <pre class="prettyprint linenums:8 lang-java"><code>
  &nbsp;usergrid_api = 'https://api.usergrid.com'
  organization = 'YOUR APIGEE.COM USERNAME'
  application = 'sandbox'
  </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-two"></span>
      <dt><h2>Set some details for your first object</h2></dt>
      <dd>
        On line 23, enter the title of your favorite book below, instead of “the old man and the sea”. Keep the entity name as “book”, otherwise we won’t know you completed the example!
  <pre class="prettyprint linenums:19 lang-java"><code>
  begin
    puts "Success! Here is the object we stored; "
    puts "notice the timestamps and unique id we created for you:"
    response = application.create_book name: 'the old man and the sea'
  rescue
    puts "Could not create the book. Did you enter your organization (username) correctly on line 10 of ruby_example.rb?"
  end
  </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-three"></span>
      <dt><h2>Now, run it!</h2></dt>
      <dd>
        You’re good to go! Run the example by entering this from the terminal window: <br><pre>ruby ruby_example.rb</pre>
      </dd>
    </dl>
  </div>

  <!-- NodeJS -->
  <div id="node" class="sdk-content">
    <div class="btn-txt sdk-button node">
      <a class="btn" href="https://github.com/apigee/appservices-nodejs-template/archive/apigee.zip" onmousedown="_gaq.push(['_trackEvent', 'SDK', 'Download', 'node']);" target="_blank" style="font-size: 16px;">Download SDK &amp; Example<br><span class="btn-btm">NodeJS</span></a>
    </div>
    <dl>
      <span class="step step-one"></span>
      <dt><h2>Set your account details in the app</h2></dt>
      <dd>
   Extract the zip file. npm install needs to be run to make sure the module is installed.  If you need to install node or npm, you can find instructions in the README.txt file. Open index.js in any text editor or your preferred IDE. On line 15, enter your "orgName" — it’s the username you picked when you signed up at <a href="http://apigee.com/about">apigee.com</a>. Keep the "appName" set as “sandbox”: it’s a context we automatically created for you. It’s completely open by default, but don’t worry, other apps you create are not!
  <pre class="prettyprint linenums:13 lang-java"><code>
  var client = new Usergrid.client({
      orgName:'YOUR APIGEE.COM USERNAME',
      appName:'sandbox',
  });
  </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-two"></span>
      <dt><h2>Set some details for your first object</h2></dt>
      <dd>
        On line 30, enter the title of your favorite book, instead of “the old man and the sea”. Keep the type as “book”, otherwise we won’t know you completed the example!
  <pre class="prettyprint linenums:27 lang-java"><code>
  var options = {
    type:"book",
    title:"the old man and the sea"
  };
  </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-three"></span>
      <dt><h2>Now, run it!</h2></dt>
      <dd>
        You’re good to go! Open a terminal, navigate to this directory and run by entering: <pre>node index.js</pre>
      </dd>
    </dl>
  </div>

  <!-- Rails -->
  <div id="rails" class="sdk-content">
    <div class="btn-txt sdk-button rails">
      <a class="btn" href="https://github.com/apigee/appservices-rails-template/archive/apigee.zip" onmousedown="_gaq.push(['_trackEvent', 'SDK', 'Download', 'Rails']);" target="_blank" style="font-size: 16px;">Download SDK &amp; Example<br><span class="btn-btm">Rails</span></a>
    </div>
    <dl>
      <span class="step step-one"></span>
      <dt><h2>Set your account details in the app</h2></dt>
      <dd>
  Extract the zip file and install the gem by opening a terminal window, navigating to this directory and entering:
  <strong>bundle install</strong>.
  Next open config/usergrid.yml in a text editor (Notepad, TextMate, SublimeText, or your preferred IDE). On lines 15/20/25, enter your {org-name} — it’s the username you picked when you signed up at apigee.com. Keep the {app-name} set as “sandbox”: it’s a context we automatically created for you. It’s completely open by default, but don’t worry, other apps you create are not!
  <pre class="prettyprint linenums:13 lang-java"><code>
  development:
    application_url: https://api.usergrid.com/{org-name}/sandbox
    auth_token:
    require_login: false

  test:
    application_url: https://api.usergrid.com/{org-name}/sandbox
    auth_token:
    require_login: false

  production:
    application_url: https://api.usergrid.com/{org-name}/sandbox
    auth_token:
    require_login: false
  </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-two"></span>
      <dt><h2>Set some details for your first object</h2></dt>
      <dd>
  Next open app/controllers/home_controller.rb. On line 8, enter the title of your favorite book, instead of “the old man and the sea”. Keep the type as “book”, otherwise we won’t know you completed the example!
  <pre class="prettyprint linenums:6 lang-java"><code>
  @book = Book.new name:"the old man and the sea"
  </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-three"></span>
      <dt><h2>Now, run it!</h2></dt>
      <dd>
        You’re good to go! Run the example with the following console command: <pre>rails s</pre>
        and navigate to http://0.0.0.0:3000 in your browser.
      </dd>
    </dl>
  </div>

  <!-- .NET -->
  <div id="dotnet" class="sdk-content">
    <div class="btn-txt sdk-button dotnet">
      <a class="btn" href="https://github.com/apigee/usergrid-.net-sdk/archive/master.zip" onmousedown="_gaq.push(['_trackEvent', 'SDK', 'Download', 'C#']);" target="_blank" style="font-size: 16px;">Download SDK &amp; Example<br><span class="btn-btm">.NET</span></a>
    </div>
    <dl>
      <span class="step step-one"></span>
      <dt><h2>Set your account details in the app</h2></dt>
      <dd>
        Extract the zip file and build the SDK from source or use Nuget.
        Next, open Program.cs in a text editor (Notepad, TextMate, SublimeText, or your preferred IDE). On line 19, enter your "organization" — it’s the username you picked when you signed up at <a href="http://apigee.com/about">apigee.com</a>. Keep the "application" set as “sandbox”: it’s a context we automatically created for you. It’s completely open by default, but don’t worry, other apps you create are not!
        <pre class="prettyprint linenums:18 lang-java"><code>
          var client = new Usergrid.Sdk.Client(&lt;org name&gt;, "sandbox");
        </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-two"></span>
      <dt><h2>Set some details for your first object</h2></dt>
      <dd>
        On line 47, enter the title of your favorite book, instead of “The Old Man and the Sea”. Keep the type as “book”, otherwise we won’t know you completed the example!
        <pre class="prettyprint linenums:45 lang-java"><code>
          Book newBook = new Book();
          newBook.title = "The Old Man and the Sea";
          client.CreateEntity<Book>("books", newBook);
        </code></pre>
      </dd>
    </dl>
    <dl>
      <span class="step step-three"></span>
      <dt><h2>Now, run it!</h2></dt>
      <dd>
        You’re good to go! Just select an emulator to  run the app on and see if the example completes!
      </dd>
    </dl>
  </div>
</div>
<div class="whats-next-block">
  <h2>What's Next?</h2>
  <div class="documentation">
    <h3><a href="http://apigee.com/docs/content/build-apps-home" target="_blank">Check out our documentation</a></h3>
    <p><strong>What can you build?</strong> Go to the docs to learn more about Apigee and what you can do with it. We have more advanced walkthroughs and samples there.</p>
  </div>
  <div class="admin-portal">
    <?php if ($is_authenticated): ?>
      <h3><a href="https://apigee.com/appservices" target="_blank">Go to the admin portal</a></h3>
    <?php else: ?>
      <h3><a href="sign-on">Go to the admin portal</a></h3>
    <?php endif; ?>
      <p><strong>CRUD your data,</strong> create more Apigee projects, and get analytics on your APIs through the Apigee developer admin console.</p>
  </div>
</div>
