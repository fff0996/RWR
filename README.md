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
````````````````````````
#Entrez(integar)
 gene1
 gene2
 gene3
 gene4
 gene5
 gene9
 gene10
 .....
 ``````````````````````
 make_geneweight.pl
 ========================
 Frequency gene count
 If geneA count is high, geneA's weight is high
 
 input file1: db
 
 

