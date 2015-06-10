var tender_buttons = "Out of kindness comes redness and out of rudeness comes rapid same question, out of an eye comes research, out of selection comes painful cattle. So then the order is that a white way of being round is something suggesting a pin and is it disappointing, it is not, it is so rudimentary to be analysed and see a fine substance strangely, it is so earnest to have a green point not to red but to point again.  A large box is handily made of what is necessary to replace any substance. Suppose an example is necessary, the plainer it is made the more reason there is for some outward recognition that there is a result. A box is made sometimes and them to see to see to it neatly and to have the holes stopped up makes it necessary to use paper. A custom which is necessary when a box is used and taken is that a large part of the time there are three which have different connections. The one is on the table. The two are on the table. The three are on the table. The one, one is the same length as is shown by the cover being longer. The other is different there is more cover that shows it. The other is different and that makes the corners have the same shade the eight are in singular arrangement to make four necessary. Lax, to have corners, to be lighter than some weight, to indicate a wedding journey, to last brown and not curious, to be wealthy, cigarettes are established by length and by doubling. Left open, to be left pounded, to be left closed, to be circulating in summer and winter, and sick color that is grey that is not dusty and red shows, to be sure cigarettes do measure an empty length sooner than a choice in color. Winged, to be winged means that white is yellow and pieces pieces that are brown are dust color if dust is washed off, then it is choice that is to say it is fitting cigarettes sooner than paper. An increase why is an increase idle, why is silver cloister, why is the spark brighter, if it is brighter is there any result, hardly more than ever.";

function deform() {
	var words, taggedWords, results, fragments, fragment_length, current_fragment;
	words = new Lexer().lex(tender_buttons);
	//taggedWords = new POSTagger().tag(words);
	result = "";
	fragments = [];
	fragment_length = 20;
	current_fragment = "";
	_.each(words, function(word, i) {
		if(word == "," || word == ".") { return; }
		if((current_fragment + " " + word).length <= fragment_length) {
			current_fragment += " " + word;
		} else {
			fragments.push(sprintf("%-20s", current_fragment));
			if (word.length <= fragment_length) {
				current_fragment = word;
			}
		}
	}); 
	$('#output').html("Number of Fragments: " + fragments.length + "\n\nJSON Fragments:\n" + JSON.stringify(fragments).replace('[',"[\n  ").replace(']',"\n]").replace(/,/g,",\n  "));
}

$(document).ready(function() {
	deform();
})
