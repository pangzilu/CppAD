var list_across0 = [
'_contents.htm',
'_reference.htm',
'_index.htm',
'_search.htm',
'_external.htm'
];
var list_up0 = [
'cppad.htm',
'appendix.htm',
'whats_new.htm',
'whats_new_10.htm'
];
var list_current0 = [
'whats_new_10.htm#Introduction',
'whats_new_10.htm#12-31',
'whats_new_10.htm#11-27',
'whats_new_10.htm#09-26',
'whats_new_10.htm#09-22',
'whats_new_10.htm#08-21',
'whats_new_10.htm#07-14',
'whats_new_10.htm#07-11',
'whats_new_10.htm#06-01',
'whats_new_10.htm#04-28',
'whats_new_10.htm#04-26',
'whats_new_10.htm#04-24',
'whats_new_10.htm#04-01',
'whats_new_10.htm#03-11',
'whats_new_10.htm#03-10',
'whats_new_10.htm#03-09',
'whats_new_10.htm#03-03',
'whats_new_10.htm#02-11',
'whats_new_10.htm#02-08',
'whats_new_10.htm#02-06',
'whats_new_10.htm#02-05',
'whats_new_10.htm#02-03',
'whats_new_10.htm#01-26',
'whats_new_10.htm#01-24',
'whats_new_10.htm#01-23',
'whats_new_10.htm#01-20',
'whats_new_10.htm#01-18',
'whats_new_10.htm#01-04'
];
function choose_across0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_across0[index-1];
}
function choose_up0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_up0[index-1];
}
function choose_down3(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down3[index-1];
}
function choose_down2(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down2[index-1];
}
function choose_down1(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down1[index-1];
}
function choose_down0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down0[index-1];
}
function choose_current0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_current0[index-1];
}