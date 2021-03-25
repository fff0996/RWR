#!/usr/bin/perl

use strict;
use warnings;

my $net =$ARGV[0];
my $db =$ARGV[1];

my $result = $ARGV[2];

my %hash; #key : gene

open(N,$net);
while(<N>){
     my $i=$_;
     chomp($i);
     my @tmp = split(/\s+/,$i);
     $hash{$tmp[0]} =1;
     $hash{$tmp[1]} =1;
}
close N;

open(D,$db);
while(<D>){
     my $i=$_;    
     chomp($i);
     my @tmp1= split(/\s+/,$i);
     for(my $k=1;$k <= $#tmp1; $k++){
          $hash{$tmp1 [$k]}=1;
     }
}
close D;

open(O,">$result");

my @gene = sort keys(%hash);
for(my $i=0; $i<=$#gene; $i++){
    print O $gene[$i],"\n";
}
close O;














