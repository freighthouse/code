<div class="row student-landing-page">
    <div class="col-sm-12">
        <!-- <div class="col-sm-12 container-spacing"> -->
        <div class="mybook-list panel">
            <div class="book-list-header">
            <h4>MY BOOK LIST</h4>
            </div>
            <div>
                <div class="row" id="mybook-list">
                    <div class="col-sm-6 my-book-txt">
                        <p class="book-list-txt">Take the reading Passage Challenge to practice your reading skills and earn rewards.</p>
                        <?php if($has_interests && $completed_challenges){ ?>
                            <?php /*print($list_link); */?>
                            <button type="button" class="btn view-book-btn" data-toggle="modal" data-target="#modal-book-list"><i class="fa fa-book" aria-hidden="true"></i> Book List</button>
                        <?php } else { ?>
                            <a class="btn view-book-btn" disabled> Book List</a> <img src="/sites/all/themes/custom/rif/src/assets/images/home_booklist_lock.png" alt="blue lock">
                        <?php } ?>
                    </div>
                    <div class="col-sm-6"></div>
                </div>
            </div>
        </div>
    </div>
</div>

<div class="modal modal-book-list fade" tabindex="-1" role="dialog" id="modal-book-list">
    <div class="modal-dialog modal-lg" role="document">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>

                <h4 class="modal-title">
                    <?php print($user_name);?>'s Booklist
                </h4>
            </div>
            <div class="modal-body">

                <div class="slider-header">
                    <input class="btn btn-yellow pull-right hidden-xs hidden-sm print-booklist" type="button" value="Print Booklist" />
                    <p>Based on your reading level and interests: <strong>
		                    <?php print($interest_names); ?>
                        </strong></p>
                    <p>Visit your school or public library to find the books on this list.</p>

                    <input class="btn btn-yellow pull-right visible-xs-block visible-sm-block hidden-md hidden-lg" type="button" onclick="printBookList('bookList')" value="Print Booklist" />
                </div>

                <div class="hidden" id="bookList">

                    <div class="container">

                        <div class="row">

                            <div class="col-xs-12">

                                <img src="/sites/all/themes/custom/rif/public/assets/images/print-rc-logo-dark.png"  />
                                <h2 class="text-center"><?php print($user_name);?>'s Book List</h2>
                                <p class="text-center">Based on your reading level and interests: <br>
                                    <strong><?php print($interest_names); ?></strong></p>
                                <p class="text-center">Visit your school or public library to find the books on this list.</p><br/>

                                <?php foreach($books_for_print as $book) : ?>

                                    <p>
                                        <img src="<?php print($book['book_cover']) ?>" style="width: 7%; height: auto; margin-left: 0; margin-bottom: 0; margin-right: 10px; float: left;">
                                        <span class="fa fa-square-o"></span>&nbsp<?php print($book['book_title']); ?> by <i><?php print($book['book_author']); ?></i><br>
                                        <a href="http://www.rif.org/<?php print($book['book_link']);?>"></a>
                                    </p><br/>

                                <?php endforeach; ?>
                            </div>

                        </div>

                    </div>

                </div>

                <div class="book-list-slider">
                    <?php
                    foreach($books as $book) {
                        $node = node_load($book);
                        $node_view = node_view($node, 'lt_book_list');
                        $rendered_node = drupal_render($node_view);
                        echo $rendered_node;
                    } ?>
                </div>

                <div class="slider-footer">
                    <h5 class="text-center">Remember!</h5>
                    <p class="text-center">Every time your reading level changes you will receive a new book list! Check back for your recommended titles after each Reading Challenge.</p>
                </div>
            </div>
        </div><!-- /.modal-content -->
    </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<?php if(!$has_interests) { ?>
    <script>
    (function ($, global) {
        $(document).ready(function () {
            console.log("InitFired");
            $('.interests-modal').click();
        });
    })(jQuery, window);
    </script>
<?php } ?>
