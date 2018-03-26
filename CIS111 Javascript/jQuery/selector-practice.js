var main = function () {
	"use strict";
	//window.alert("hello world!");
	//console.log($("h2")[0].innerHTML);
	$("h2:first" ).css("font-style", "italic");
	//alert($("h2:eq(1)").html());
	//$("h2")[0].html("DEF");
	//alert($("h2")[0].html());

//1. Select the <h1> element.
$("h1" ).css("backgroundColor", "DodgerBlue");
//2. Select the <h2> element by its class.
$("h2.important" ).css("backgroundColor", "Gold");
//3. Select all of the relevant paragraphs.
$(".relevant p").css("backgroundColor", "Red");
//4. Select the first paragraph of the relevant paragraphs.
$(".relevant p").eq(0).css("backgroundColor", "Blue")
//5. Select the third paragraph of the relevant paragraphs.
$(".relevant p").eq(2).css("backgroundColor", "Green");
//6. Select the seventh relevant paragraph.//css method can take either a property name and value, 
//or a single object of key-value pairs.

//7. Select all of the paragraphs on the page.

//8. Select only the random, unattached paragraph
$("p").not(".relevent p").css("backgroundColor", "Aqua");
};

$(document).ready(main);