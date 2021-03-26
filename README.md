# RWR

make_genelist.pl
====================
gather network gene and db gene 

input file1: net 
`````````````````````
#Entrez(integar)
gene1\tgene2\tscore
gene3\tgene4\tscore
gene3\tgene9\tscore
....
```````````````````````
input file2: db
``````````````````````
#Entrez(integar)
Target1\tgene3\tgene5\tgene1....
Target2\tgene1\tgene9...
Taget3\tgene10....
...
```````````````````````
input file3: output (output file)
`````````````````````
#Entrez(integar)
 gene1
 gene2
 gene3
 gene4
 gene5
 gene9
 gene10
 .....
 ``````````````````````````
 make_geneweight.pl
 ========================
 Frequency gene count
 If geneA count is high, geneA's weight is high
 So we count db's gene
 input file1: db
 `````````````````
 #Entrez(integar)
Target1\tgene3\tgene5\tgene1....
Target2\tgene1\tgene9...
Taget3\tgene10....
...
``````````````````
input file2: output (output file)
```````````````````
gene1\tcount
gene3\tcount
gene5\tcount
gene9\tcount
gene10\tcount
...
```````````````````
make_input_drug.pl
==================
To make input_drug(vector).
input_drug(gene) is geneset.

input 1:drug_name

input file2: db
````````````````````
 #Entrez(integar)
Target1\tgene3\tgene5\tgene1....
Target2\tgene1\tgene9...
Taget3\tgene10....
...
````````````````````
input file3: gene_weight (make_geneweight.pl outputfile)
``````````````````````````````````````````````````````````
gene1\tcount
gene3\tcount
gene5\tcount
gene9\tcount
gene10\tcount
...
``````````````````````````````````````````````````````````
input file4: geneset (output file)
```````````````````````````````````
input Drug's target gene1\tweight
input Drug's target gene2\tweight
input Drug's target gene3\tweight
....
```````````````````````````````````
RandomWalkingScoring.c
=================================
Randomwalkscoring

input file1: whole_gene(make_genelist.pl output)
```````````````````````````````````````````````````
Target1\tgene3\tgene5\tgene1....
Target2\tgene1\tgene9...
Taget3\tgene10....
...
````````````````````````````````````````````````````
input file2: net
`````````````````````````````
gene1\tgene2\tscore
gene3\tgene4\tscore
gene3\tgene9\tscore
....
`````````````````````````````
input file3: geneset(make_input_drug.pl output file)
``````````````````````````````````````````````````````
input Drug's target gene1\tweight
input Drug's target gene2\tweight
input Drug's target gene3\tweight
....
``````````````````````````````````````````````````````
input4 : restart prob 

output file
``````````````````````````````````````````````````````
input Drug_name\tscore1\tscore2\tscore3\score4......
````````````````````````````````````````````````````````
 
 
 

