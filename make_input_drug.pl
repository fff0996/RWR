#!/usr/bin/perl

use strict;
use warnings;

my $drug=$ARGV[0];
my $db=$ARGV[1];
my $gene_weight=$ARGV[2];
my $geneset=$ARGV[3];

open(O,">$geneset");
my %hash;

open(D,$db);
while(<D>){
	
	my $i=$_;
	chomp($i);
	my @line=split(/\s+/,$i);
	if($drug eq $line[0]){
		for(my $j=1; $j <=( scalar @line)-1;$j++){
			push(@{$hash{$drug}},$line[$j]);
		}
	}else{
		next;
	}
}
close D;

my %gene;
open(G,$gene_weight);
while(<G>){

	my $i=$_;
	chomp($i);
	my @line=split(/\s+/,$i);
	$gene{$line[0]}=$line[1];
}
close G;
#my @gene=sort{$a <=> $b}(keys %gene);
for my $i (@{$hash{$drug}}){
	print O $i,"\t",$gene{$i},"\n";
}
#binary search

#for my $value (@{$hash{$drug}}){
#	my $first=0;
#	my $last=(scalar @gene) -1;
#	my $index=-1;
#	while($first <= $last and $index=-1){
#		my $mid=int(($first+$last)/2);
#		if($value == $gene[$mid]){
#			$index=$mid;
#			print O $value,"\t",$gene{$value},"\n";
#			last;
#		}elsif($value < $gene[$mid]){
#			$last=$mid-1;
#		}else{
#			$first=$mid+1;
#		}
#	}
#}
#close O;
		
