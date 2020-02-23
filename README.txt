page-blocked.ref:												
												
												
memory size: 50												
												
			Hit rate    Hit count   Miss count    Overall eviction count    Clean eviction count	Dirty eviction count
												
fifo		99.8245		3507538		6166		  6116				  	    4121					1995
												
lru			99.8618		3508848		4856		  4806						2604					2202
												
clock		99.8616		3508841		4863		  4813						2657					2156
												
												
												
memory size: 100												
												
		    Hit rate	Hit count	Miss count    Overall eviction count	Clean eviction count	Dirty eviction count
												
fifo		99.8817		3509549		4155		  4055						2738					1317
												
lru			99.8971		3510089		3615		  3515						2568					947
												
clock		99.8908		3509868		3836		  3736						2564					1172
											




page-matmul.ref:												
												
												
memory size: 50												
												
			Hit rate	Hit count	Miss count	  Overall eviction count	Clean eviction count	Dirty eviction count
												
fifo		62.9391		1913768		1126896		  1126846					1104455					22391
												
lru			65.7665		1999739		1040925		  1040875					1039914					961
												
clock		65.7663		1999733		1040931		  1040881					1039917					964
												
												
												
memory size: 100												
												
			Hit rate	Hit count	Miss count	  Overall eviction count	Clean eviction count	Dirty eviction count
												
fifo		64.3709		1957302		1083362		  1083262					1071710					11552
												
lru			66.9061		2034389		1006275		  1006175					1005215					960
												
clock		65.7699		1999841		1040823		  1040723					1039762					961
												




page-simpleloop.ref:												
												
												
memory size: 50												
												
			Hit rate	Hit count	Miss count	  Overall eviction count	Clean eviction count	Dirty eviction count
												
fifo		22.4822		759			2617		  2567						45						2522
												
lru			25.2073		851			2525		  2475						0						2475
												
clock		25.1481		849			2527		  2477						0						2477
												
												
												
memory size: 100												
												
			Hit rate	Hit count	Miss count	  Overall eviction count	Clean eviction count	Dirty eviction count
												
fifo		23.7855		803			2573		  2473						23						2450
												
lru			25.2073		851			2525		  2425						0						2425
												
clock		25.0889		847			2529		  2429						1						2428
												



Comparing the various algorithms:
For simpleloop.c, Lru and clock have better hit rate than fifo. Their hit rates are all around 25%. 
For matmul.c, when memory size is 50, clock and lru have samilar hit rate and they are better than fifo. 
When memory size is 100,  lru has the best hit rate. For block.c and both memory size, lru is 
slight better than clock and fifo. Fifo has the worst hit rate in both memory size.

Generally, lru has the best hit rate, but there is not a large difference between lru and clock usually.  
Fifo always have the worst hit rate.  Sicne lru is just slight better than clock and clock is cheaper in space, 
that's why we think clock is a good algo for page replecement.




trace1.ref:
	fifo:
		Hit count: 22
		Miss count: 17
		Clean evictions: 0
		Dirty evictions: 9
		Total references : 39
		Hit rate: 56.4103
		Miss rate: 43.5897

	lru:
		Hit count: 17
		Miss count: 22
		Clean evictions: 1
		Dirty evictions: 13
		Total references : 39
		Hit rate: 43.5897
		Miss rate: 56.4103
		
	clock:
		Hit count: 21
		Miss count: 18
		Clean evictions: 1
		Dirty evictions: 9
		Total references : 39
		Hit rate: 53.8462
		Miss rate: 46.1538

	opt:
		Hit rate: 25/40 = 62.5%


trace2.ref:
	fifo:
		Hit count: 11
		Miss count: 21
		Clean evictions: 2
		Dirty evictions: 11
		Total references : 32
		Hit rate: 34.3750
		Miss rate: 65.6250

	lru:
		Hit count: 17
		Miss count: 15
		Clean evictions: 0
		Dirty evictions: 7
		Total references : 32
		Hit rate: 53.1250
		Miss rate: 46.8750

	clock:
		Hit count: 11
		Miss count: 21
		Clean evictions: 2
		Dirty evictions: 11
		Total references : 32
		Hit rate: 34.3750
		Miss rate: 65.6250

	opt:
		Hit rate: 17/32 = 53.125%


trace3.ref:
	fifo:
		Hit count: 0
		Miss count: 48
		Clean evictions: 10
		Dirty evictions: 30
		Total references : 48
		Hit rate: 0.0000
		Miss rate: 100.0000

	lru:
		Hit count: 0
		Miss count: 48
		Clean evictions: 10
		Dirty evictions: 30
		Total references : 48
		Hit rate: 0.0000
		Miss rate: 100.0000

	clock:
		Hit count: 0
		Miss count: 48
		Clean evictions: 10
		Dirty evictions: 30
		Total references : 48
		Hit rate: 0.0000
		Miss rate: 100.0000

	opt:
		Hit rate: 16/48 = 33.333%