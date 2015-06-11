# Sixth Dimensional Stein

This project, by [Margaret Konkol](https://twitter.com/mekonkol) and [Andrew Pilsch](https://twitter.com/oncomouse), responds to course themes in our [DHSI 2015 Physical Computing course](https://github.com/uvicmakerlab/dhsi2015/blob/master/index.md) by placing Gertrude Stein in a box.

Using an Arduino, we created a device (source code in `arduino-code`) that opens a box, displays a random poem built from Stein's *Tender Buttons*, and then, when the user loses interest, destroys the poem.

## Sources

The poem fragments are assembled from the "Objects" section of *Tender Buttons* that are both titled "A BOX." They read:

> A BOX.
>
>Out of kindness comes redness and out of rudeness comes rapid same question, out of an eye comes research, out of selection comes painful cattle. So then the order is that a white way of being round is something suggesting a pin and is it disappointing, it is not, it is so rudimentary to be analysed and see a fine substance strangely, it is so earnest to have a green point not to red but to point again. 

And:

> A BOX.
>
>A large box is handily made of what is necessary to replace any substance. Suppose an example is necessary, the plainer it is made the more reason there is for some outward recognition that there is a result.
>
>A box is made sometimes and them to see to see to it neatly and to have the holes stopped up makes it necessary to use paper.
>
>A custom which is necessary when a box is used and taken is that a large part of the time there are three which have different connections. The one is on the table. The two are on the table. The three are on the table. The one, one is the same length as is shown by the cover being longer. The other is different there is more cover that shows it. The other is different and that makes the corners have the same shade the eight are in singular arrangement to make four necessary.
>
>Lax, to have corners, to be lighter than some weight, to indicate a wedding journey, to last brown and not curious, to be wealthy, cigarettes are established by length and by doubling.
>
>Left open, to be left pounded, to be left closed, to be circulating in summer and winter, and sick color that is grey that is not dusty and red shows, to be sure cigarettes do measure an empty length sooner than a choice in color.
>
>Winged, to be winged means that white is yellow and pieces pieces that are brown are dust color if dust is washed off, then it is choice that is to say it is fitting cigarettes sooner than paper.
>
>An increase why is an increase idle, why is silver cloister, why is the spark brighter, if it is brighter is there any result, hardly more than ever. 

## Assembling the Fragments

We used a JavaScript lexer called [jspos](https://code.google.com/p/jspos/) to break the text into single words. We then assembled these words into fragments that were 20 characters or fewer (`lexing-tender-buttons/tender-buttons.js` for the source code; `lexing-tender-buttons/tender-buttons.html` for the compiled program).

## The Arduino Program

From the lexer, we built an Arduino program (`arduino-code/tender-buttons.ino`) that contained the fragments, and some simple logic to:

1. Wait for a user to interact with a touch sensor.
1. On detecting a touch, open the box lid.
1. When the lid is open, generate a random set of four lines and display them to the user.
1. Wait for the user to maintain contact with the touch sensor.
1. When contact is broken, clear the display and close the lid.