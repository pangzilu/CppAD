var list_across0 = [
'_contents.htm',
'_reference.htm',
'_index.htm',
'_search.htm',
'_external.htm'
];
var list_up0 = [
'cppad.htm',
'speed.htm',
'speed_cppadcg.htm',
'cppadcg_det_minor.cpp.htm',
'cppadcg_det_minor_grad.c.htm'
];
var list_current0 = [
'cppadcg_det_minor_grad.c.htm#Syntax',
'cppadcg_det_minor_grad.c.htm#Prototype',
'cppadcg_det_minor_grad.c.htm#Purpose',
'cppadcg_det_minor_grad.c.htm#optimize',
'cppadcg_det_minor_grad.c.htm#size',
'cppadcg_det_minor_grad.c.htm#x',
'cppadcg_det_minor_grad.c.htm#y',
'cppadcg_det_minor_grad.c.htm#flag',
'cppadcg_det_minor_grad.c.htm#Implementation'
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