/*
 * # @author: Jeremy Cerda
 * # @version: $Id: show_teasers.js 2750 2011-10-11 18:59:48Z jcerda $
 */

Drupal.behaviors.theme_MNI_showTeasers = function(context, settings)
{
	$("ul.articles-list li").each(function(i) {
        	$(this) .children("p")
			.not("p.dashline")
			.not("p.byline")
                	.slice(0,4)
	                .show();

        	$(this) .children("div.views-field-teaser")
                	.children("div.field-content")
	                .children("p")
			.not("p.dashline")
			.not("p.byline")
        	        .slice(0,4)
                	.show();
	});
};
