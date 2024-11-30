/* 
	Content UI Sphinx Extension

	- https://github.com/ulrobix/sphinxcontrib-contentui -
	
	Copyright (c) 2017 Robert

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

$(function() {
    /*
     * Right column logic
     */
    if ($(".right-col").length) {
        $(".right-col").after('<div class="clear"></div>');
        $(".right-col").parents('body').addClass('with-columns');
    }

    /**
     * Toggle logic
     */
    $('.toggle-content').hide()
    $('.toggle-header').click(function () {
        $(this).toggleClass("open");
        $(this).next('.toggle-content').toggle('400');
    })
    
    /**
     * Dynamic multiple content block.
     */
    var top_sel = {}

    $('div.content-tabs').each(function() {
        var contenttab_sel = $('<ul />', { class: "contenttab-selector" });
        var i = 0;

        if ($(this).hasClass('right-col')){
            contenttab_sel.addClass('in-right-col');
        }

        $('.tab-content', this).each(function() {
            var sel_item = $('<li />', {
                class: $(this).attr('id'),
                text: $(this).find('.tab-title').text()
            });
            $(this).find('.tab-title').remove();
            if (i++) {
                $(this).hide();
            } else {
                sel_item.addClass('selected');
            }
            contenttab_sel.append(sel_item);
            $(this).addClass('contenttab');
        });

        $('.tab-content', this).eq(0).before(contenttab_sel);
        contenttab_sel = null;
        i = null;
    });


    $('.contenttab-selector li').click(function(evt) {
        evt.preventDefault();

        if ($(this).parents('.in-right-col').length){
            var tabsblock = $('.right-col');
        }else{
            var tabsblock = $(this).parents('.content-tabs');
        }

        var sel_class = $(this).attr('class');
        $('div.contenttab',tabsblock).hide();
        $('div#' + sel_class,tabsblock).show();

        $('ul.contenttab-selector li', tabsblock).removeClass('selected');
        $('ul.contenttab-selector li.' + sel_class, tabsblock).addClass('selected');

        sel_class = null;
    });

});

