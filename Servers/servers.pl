#perl
my @servers = lxq("query hostservice servers ?");
foreach my $server (@servers)
{
	lxout("${server}");
}