<div class="row student-landing-page">
  <div class="col-sm-12 container-spacing">
    <h4 class="header-about-me">ABOUT ME</h4>
    <div class="row content-list">
      <div class="">
        <div class="col-sm-6 rt-book-list">
          <div class="about-me-txt">
            <p class="about-me-txt-quest">Your Name</p> <p class="about-me-txt-answer"><?php print $name; ?></p>
          </div>
          <div class="about-me-txt">
            <p class="about-me-txt-quest">Teacher/Parent</p> <p class="about-me-txt-answer"><?php print $managing_user; ?></p>
          </div>
          <div class="about-me-txt">
            <p class="about-me-txt-quest">Reading Group</p> <p class="about-me-txt-answer"><?php print $reading_group; ?></p>
          </div>
        </div>
        <div class="col-sm-6 rt-book-list">
          <div class="about-me-txt">
            <p class="about-me-txt-quest">Grade</p> <p class="about-me-txt-answer"><?php print $grade_level; ?></p>
          </div>
          <div class="about-me-txt">
            <p class="about-me-txt-quest">Interests</p> <p class="about-me-txt-answer"><?php print $interests; ?></p>
          </div>
          <?php print $interests_modal_link; ?>
        </div>
      </div>
    </div>
  </div>
</div>
