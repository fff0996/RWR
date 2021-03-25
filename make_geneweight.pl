#!/usr/bin/perl

use strict;
use warnings;

my $db=$ARGV[0];
my $gene_weight=$ARGV[1];

open(D,$db);
open(G,">$gene_weight");

my %hash;
while(<D>){

	my $i=$_;
	chomp($i);
	my @line=split(/\s+/,$i);
	for(my $index=1; $index<=(scalar @line -1);$index++){
		if(exists $hash{$line[$index]}){
			$hash{$line[$index]}++;
		}else{
			$hash{$line[$index]}=1;
		}
	}
}
close D;
my @keys=keys %hash;
print scalar @keys,"\n";
for my $key (keys %hash){
	print G $key,"\t",$hash{$key},"\n";
}
close G;	
