## IP Filter
Program read data from standart input line by line.
Line format:     ``text1 \t text2 \t text3 \n``.

Only ``text1`` is valuable. It contains ip adress (ip4): 
>n1.n2.n3.n4,

where **n1..4** - numbers from 0 to 255.

**Task**

Load ip adresses list and output in reverse lexigraphically order like this:

* 192.10.1.1
* 192.2.1.1
* 192.1.1.1

Then added output with adresses started with "1".
Then added output with adresses started with "46.70".
Then added output with adresses containing "46".
