/*
 * Day 16 - ticket scanning
 */

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

#if 1
#define RULES_LEN 20
const char* rulesInput[20] = 
{
"departure location: 47-164 or 179-960",
"departure station: 49-808 or 833-968",
"departure platform: 50-561 or 567-964",
"departure track: 29-407 or 416-954",
"departure date: 48-317 or 339-965",
"departure time: 42-366 or 390-952",
"arrival location: 45-292 or 304-974",
"arrival station: 26-255 or 266-951",
"arrival platform: 47-225 or 243-957",
"arrival track: 37-442 or 452-954",
"class: 35-120 or 127-958",
"duration: 47-642 or 659-972",
"price: 39-509 or 535-962",
"route: 47-705 or 729-962",
"row: 49-480 or 494-959",
"seat: 28-846 or 865-969",
"train: 30-598 or 606-968",
"type: 42-905 or 924-965",
"wagon: 29-884 or 899-973",
"zone: 39-790 or 803-969"
};
#endif

#if 0
#define RULES_LEN 3
const char* rulesInput[3] = 
{
"class: 0-1 or 4-19",
"row: 0-5 or 8-19",
"seat: 0-13 or 16-19"
};
#endif

#if 1
std::vector<std::vector<int>> nearbyTickets = 
{
{132,244,97,308,641,251,155,157,783,748,330,665,873,111,736,943,570,463,254,305},
{274,568,501,738,458,742,271,756,320,572,194,213,667,456,625,617,705,468,739,756},
{57,359,808,104,882,270,613,285,780,430,497,434,895,67,735,688,901,310,668,288},
{732,132,437,243,772,677,641,872,163,222,153,360,342,669,399,222,112,128,607,175},
{217,254,840,734,185,777,315,131,947,671,767,928,660,458,246,5,76,782,780,111},
{273,701,102,731,899,738,89,784,391,586,146,472,449,69,761,339,138,255,779,346},
{689,877,98,618,748,418,788,593,117,803,702,547,116,131,766,70,506,310,529,782},
{300,742,398,112,678,837,840,937,773,632,903,729,551,667,576,881,85,584,152,865},
{248,133,219,192,65,390,607,419,877,441,75,211,115,315,202,766,400,293,749,437},
{361,73,565,693,159,660,163,944,117,281,758,267,871,739,479,926,631,506,362,190},
{767,741,881,691,355,769,456,507,496,695,391,928,508,979,460,778,90,836,772,871},
{797,418,634,574,452,608,465,286,555,623,274,672,429,224,268,544,75,688,842,133},
{249,752,585,350,406,544,928,590,100,746,769,501,915,187,731,66,64,57,762,149},
{397,132,635,677,292,340,871,461,58,149,295,160,785,356,471,402,561,661,611,146},
{677,201,551,630,941,453,304,495,92,928,688,471,594,838,610,341,349,730,300,194},
{406,731,543,65,393,137,64,78,206,462,383,439,680,424,100,406,95,51,198,665},
{781,457,876,773,341,502,466,211,512,584,462,153,930,548,426,182,188,771,468,192},
{771,113,774,339,930,672,399,939,205,317,276,596,866,113,180,720,199,308,401,642},
{311,252,703,94,571,314,467,50,595,272,845,853,442,250,204,869,163,904,475,348},
{201,187,67,838,474,346,50,829,682,456,845,757,469,700,627,184,667,498,749,58},
{922,58,224,65,159,737,745,837,365,561,358,750,67,692,149,192,247,66,75,502},
{158,660,139,743,889,50,569,253,65,535,148,113,344,543,214,808,407,757,452,947},
{64,313,618,360,193,752,405,702,903,212,350,394,571,682,310,462,945,922,639,351},
{304,766,284,835,137,609,402,364,782,931,764,507,436,589,303,507,628,933,750,499},
{808,433,583,438,834,940,755,629,569,628,638,920,878,139,621,363,755,131,339,935},
{782,130,144,584,558,696,783,72,363,215,15,132,393,549,941,279,429,940,634,343},
{676,597,635,291,574,762,267,341,395,346,675,698,769,101,402,694,619,462,917,572},
{686,253,296,606,507,665,736,152,160,109,938,51,208,117,782,595,142,316,833,351},
{158,354,68,541,499,394,586,577,662,424,551,783,537,247,309,301,779,137,784,144},
{315,874,97,94,631,671,190,788,784,590,218,117,807,213,697,983,476,637,288,846},
{277,344,583,182,467,501,196,757,900,480,342,544,868,559,86,978,53,339,682,899},
{213,130,463,196,545,789,596,939,841,307,704,937,315,805,900,545,191,169,873,940},
{52,70,284,254,617,110,247,504,93,281,364,143,758,348,931,290,341,804,689,490},
{142,295,398,287,757,148,754,701,865,459,396,83,659,85,117,317,549,790,839,785},
{88,758,703,191,272,846,737,270,772,554,361,101,838,779,462,667,288,780,491,400},
{554,760,750,132,138,733,148,852,353,105,244,613,683,63,103,500,629,756,220,390},
{146,701,705,574,538,180,390,395,608,420,982,554,55,734,836,701,548,480,194,467},
{500,422,804,154,108,283,781,475,210,471,140,397,867,999,72,271,502,79,771,98},
{112,82,152,682,418,868,620,92,459,191,597,882,285,55,290,976,466,307,948,627},
{138,289,453,403,187,400,112,462,586,94,770,220,611,53,466,849,312,804,541,57},
{277,356,760,181,447,670,348,763,842,291,62,137,391,69,928,745,452,218,92,140},
{138,585,698,211,493,775,308,475,769,186,747,884,541,625,678,764,878,291,867,145},
{220,743,665,941,459,219,349,245,144,129,751,314,23,698,429,65,54,624,111,544},
{416,577,393,345,591,206,181,292,132,575,425,133,644,558,340,873,642,269,434,936},
{404,609,365,136,925,924,583,419,340,503,559,436,634,773,545,402,538,71,253,448},
{778,149,698,901,174,546,342,871,280,556,736,64,588,277,616,668,455,673,272,675},
{199,131,488,536,195,435,846,626,97,304,689,630,403,561,774,344,556,72,662,756},
{196,608,436,155,644,404,882,111,56,146,696,587,356,581,154,75,682,771,114,356},
{59,774,203,558,54,270,683,777,875,205,703,437,6,939,417,748,610,186,546,690},
{233,362,111,315,350,73,80,406,667,554,310,268,163,786,64,617,638,866,78,787},
{748,593,548,156,284,535,588,379,684,500,807,419,589,697,629,290,129,462,633,760},
{581,941,355,391,689,214,737,179,435,772,75,366,427,440,150,940,461,850,839,694},
{773,251,535,339,70,686,158,761,671,417,391,342,347,442,931,913,50,933,82,422},
{211,638,550,900,68,581,211,627,309,427,153,173,948,478,435,743,687,865,355,474},
{585,774,628,688,226,665,461,113,420,704,315,764,69,433,189,875,464,73,390,924},
{573,745,758,788,550,661,735,660,223,746,771,642,740,69,221,674,558,564,754,87},
{357,585,583,667,317,250,737,696,846,440,93,930,502,0,731,468,470,732,179,619},
{479,900,102,357,865,636,476,317,463,587,816,589,635,391,767,495,359,582,347,755},
{675,365,538,203,502,613,729,704,104,157,506,781,369,843,459,536,609,421,621,693},
{419,87,92,209,379,769,113,591,118,498,104,158,775,345,464,940,752,669,141,778},
{684,837,114,777,138,574,81,564,673,197,269,405,82,940,78,344,143,273,127,211},
{946,790,641,220,542,113,696,96,478,0,317,542,659,776,187,221,626,633,559,278},
{310,182,160,666,148,180,270,398,280,432,519,344,281,466,419,559,543,637,946,614},
{845,703,616,931,393,304,667,595,584,398,409,765,200,773,292,82,133,193,223,425},
{739,760,418,91,636,694,739,896,316,785,588,101,139,674,623,700,196,878,469,834},
{569,214,987,781,247,790,204,783,625,865,597,665,744,925,766,497,948,269,120,935},
{869,500,559,641,154,142,941,557,435,180,416,814,200,680,52,612,470,739,268,675},
{129,594,420,275,597,341,677,56,350,452,910,783,608,163,747,700,744,81,114,213},
{574,218,942,550,720,770,362,568,638,308,398,695,468,905,548,869,89,772,158,786},
{580,616,926,305,747,86,455,610,829,61,589,440,619,351,666,77,882,586,772,640},
{90,514,901,841,426,671,535,745,501,314,181,879,869,624,844,765,597,496,699,82},
{57,129,578,929,366,663,78,553,766,609,278,766,767,679,99,525,210,67,114,185},
{246,944,668,617,156,353,67,457,359,837,701,623,129,343,804,276,660,613,54,564},
{190,203,995,274,905,139,552,216,273,807,507,405,465,345,753,770,557,583,502,877},
{183,688,845,80,80,882,529,305,85,750,282,477,438,927,131,595,252,98,349,161},
{866,776,3,197,180,752,924,701,735,556,756,305,660,315,944,224,734,464,452,638},
{613,129,245,574,836,153,934,516,309,693,545,781,777,751,591,557,98,841,442,316},
{941,495,179,430,585,316,61,448,395,669,944,407,85,160,569,569,502,632,188,364},
{481,806,424,72,148,838,473,464,364,128,621,703,392,249,749,698,582,460,186,537},
{404,874,779,476,456,569,475,788,356,283,225,634,337,681,606,111,500,159,133,342},
{116,203,479,934,340,568,939,57,842,452,187,838,77,669,531,540,499,130,163,846},
{555,196,216,206,148,554,160,749,489,569,783,397,927,439,307,938,638,313,151,637},
{272,663,899,78,572,395,537,164,477,393,434,286,421,869,184,347,927,199,412,163},
{96,585,141,607,277,61,407,143,462,301,751,151,763,769,746,467,585,462,267,213},
{111,748,65,928,270,432,76,353,416,924,82,69,554,947,500,94,298,784,315,936},
{932,498,91,624,903,189,61,350,899,985,64,936,678,900,281,90,628,842,504,91},
{471,53,148,97,807,164,315,699,594,164,788,660,586,194,922,351,557,508,685,931},
{615,201,428,429,159,879,215,209,360,770,633,543,592,57,358,460,611,742,565,903},
{735,732,754,544,341,929,200,361,591,2,836,703,455,593,291,768,63,92,700,245},
{435,666,743,89,755,503,279,235,192,538,502,592,509,142,836,210,672,615,612,668},
{398,7,591,598,584,582,397,311,407,570,774,398,77,454,685,692,550,933,193,422},
{754,186,217,452,515,876,278,677,82,213,252,937,54,347,902,111,453,390,590,684},
{741,672,345,208,115,67,215,453,671,73,178,806,144,196,50,355,749,659,680,287},
{759,78,100,768,119,204,592,947,621,432,114,96,765,305,546,893,873,308,393,597},
{617,98,869,596,405,404,73,326,612,784,198,734,736,311,500,471,703,222,574,775},
{551,844,308,402,338,93,843,154,570,468,783,423,750,150,309,180,138,934,884,111},
{208,805,785,159,91,542,143,147,778,440,536,84,185,120,789,249,737,677,948,526},
{106,746,394,638,823,152,675,111,619,679,740,185,504,570,440,759,181,350,541,683},
{396,459,340,308,924,390,131,756,740,632,703,255,575,834,128,326,431,317,459,871},
{211,868,805,759,544,693,878,789,360,860,640,503,558,70,210,884,673,470,191,341},
{70,880,179,191,135,536,581,845,278,762,182,96,803,207,731,924,216,767,982,640},
{883,424,588,399,781,729,632,682,193,442,361,291,276,289,307,339,640,487,926,461},
{494,880,434,267,608,782,351,543,342,192,286,598,461,225,830,928,943,139,454,844},
{597,317,406,278,289,574,453,161,348,576,157,609,758,659,946,124,686,866,221,147},
{276,672,765,595,416,199,675,249,561,938,764,669,902,499,407,348,77,790,834,3},
{748,475,552,113,552,353,277,144,536,612,350,144,162,548,689,379,203,159,137,904},
{211,268,435,808,733,616,834,97,501,769,292,132,364,60,97,901,685,943,864,312},
{901,353,612,59,182,438,308,689,171,90,211,141,212,666,97,426,437,199,433,76},
{97,552,769,285,633,75,23,701,904,160,218,942,764,306,568,72,624,453,69,597},
{872,468,806,508,246,253,104,341,363,749,745,868,425,72,138,489,363,458,670,699},
{61,557,56,538,731,608,280,779,581,493,87,468,503,69,740,556,405,938,200,152},
{637,269,217,285,496,625,271,96,619,697,424,883,793,114,63,678,555,586,85,222},
{673,758,394,147,674,839,255,672,588,214,578,560,496,308,574,613,975,102,788,402},
{150,64,137,268,460,266,641,110,508,455,788,278,632,363,866,784,553,610,236,59},
{392,290,398,193,123,286,470,269,624,732,287,631,940,440,468,754,146,282,578,883},
{439,453,197,868,135,145,557,667,875,946,737,455,757,732,476,145,992,106,81,941},
{494,395,155,150,108,285,420,182,135,61,433,393,108,355,899,834,188,665,372,459},
{632,753,757,880,225,979,902,671,596,595,244,354,206,362,357,101,416,767,869,595},
{161,805,99,137,243,425,101,404,419,926,68,81,556,307,409,674,132,877,770,89},
{59,362,216,463,977,734,687,843,209,784,281,546,279,391,270,304,207,84,497,579},
{737,607,509,690,302,506,926,428,182,437,452,75,255,203,497,742,56,875,558,632},
{630,454,771,672,276,115,868,758,806,392,200,486,286,359,738,109,540,937,668,356},
{83,734,561,839,440,837,593,54,919,453,63,399,545,96,634,432,392,158,476,343},
{804,390,554,345,773,246,266,641,101,946,390,550,251,340,313,562,289,465,81,311},
{255,873,705,397,457,306,91,297,785,835,905,774,592,70,779,593,251,360,68,286},
{615,942,110,203,924,278,250,143,182,390,203,271,535,740,6,663,149,730,615,191},
{470,743,553,760,191,433,907,937,291,211,555,636,499,471,186,118,467,937,883,561},
{556,67,595,545,210,673,866,930,128,270,580,148,502,130,606,199,131,351,460,988},
{704,583,420,685,364,250,500,69,279,93,271,509,689,882,776,899,746,210,834,381},
{930,690,980,767,224,63,681,275,586,662,199,431,461,185,557,949,558,416,62,134},
{358,82,619,636,659,777,504,363,348,52,478,941,865,804,660,82,589,359,738,294},
{444,348,698,729,576,162,543,153,185,884,286,934,160,780,51,627,579,120,763,744},
{470,839,466,731,351,629,933,148,221,272,535,252,844,283,785,752,145,405,155,991},
{186,363,66,775,590,108,759,476,899,918,199,642,75,837,287,619,762,590,579,223},
{405,422,805,148,934,705,509,839,146,747,639,552,292,249,988,731,420,834,87,613},
{361,149,115,901,741,497,287,114,847,542,271,770,208,737,790,903,76,53,436,271},
{115,773,473,757,684,359,287,663,562,880,245,554,476,270,937,205,788,278,341,61},
{284,874,163,846,805,617,768,125,452,109,776,465,272,902,554,771,421,661,630,207},
{878,780,516,393,560,545,539,182,764,748,773,462,472,102,162,151,113,103,288,476},
{393,770,182,834,225,884,145,128,776,806,453,468,530,56,72,583,545,81,946,268},
{757,437,852,502,807,223,157,642,606,642,763,698,402,736,773,120,742,553,539,269},
{665,54,767,628,845,79,844,872,289,185,182,350,80,86,869,801,619,163,505,629},
{185,583,754,625,794,431,870,753,217,835,406,754,780,470,288,740,251,735,548,366},
{540,22,439,751,468,358,480,500,59,432,354,905,778,940,931,753,347,496,926,162},
{146,252,128,807,806,108,466,732,315,752,549,630,117,129,426,663,490,157,436,473},
{836,197,871,579,749,360,698,587,570,760,774,772,458,142,975,945,224,508,622,459},
{549,344,783,407,455,299,470,156,943,148,278,433,152,150,110,70,633,343,244,134},
{160,91,13,391,292,539,279,731,85,875,703,499,201,75,186,314,399,343,875,69},
{349,636,374,682,761,737,223,698,266,344,588,905,540,201,97,730,506,598,398,98},
{193,464,806,132,698,164,429,758,296,774,281,689,244,507,474,55,96,286,199,584},
{55,269,450,83,631,361,402,112,99,736,339,396,612,577,475,468,865,804,626,542},
{606,224,614,54,729,59,639,838,744,672,593,757,201,275,675,78,596,155,3,638},
{764,211,770,156,748,928,89,746,929,60,399,210,693,349,470,442,540,817,197,68},
{700,118,419,675,701,552,358,920,740,805,405,584,598,309,129,642,804,883,344,755},
{90,134,595,668,306,361,625,292,357,312,225,739,701,254,495,165,159,461,567,552},
{216,677,147,873,785,291,418,538,606,398,949,350,786,949,569,63,627,117,735,910},
{308,935,84,79,362,865,97,841,114,764,488,466,144,583,942,63,689,248,678,190},
{506,627,508,498,459,606,469,357,116,196,215,96,415,161,180,218,777,350,100,744},
{765,630,216,578,274,576,613,479,221,606,398,198,814,865,905,580,871,340,558,313},
{352,63,689,480,908,641,201,749,339,570,758,622,77,179,64,204,185,420,266,273},
{115,502,470,189,127,693,162,415,596,471,678,838,199,138,836,871,667,313,398,607},
{407,629,274,616,476,616,68,792,496,673,216,805,285,579,591,876,281,53,580,557},
{785,427,413,695,251,676,688,199,537,683,72,358,771,507,224,206,737,550,501,276},
{91,109,433,734,458,623,694,592,745,151,674,472,927,883,882,71,576,158,614,236},
{288,425,803,271,905,146,156,218,673,426,987,870,360,808,244,97,163,586,584,418},
{741,684,68,739,278,494,435,544,267,591,735,763,365,483,200,866,681,507,466,113},
{70,59,416,583,50,841,161,787,417,221,702,785,139,130,574,750,867,526,544,120},
{874,459,580,195,670,634,396,148,266,78,159,427,290,598,617,764,363,537,392,814},
{421,352,307,881,82,558,302,748,308,418,214,678,281,875,464,729,567,399,686,692},
{321,62,839,596,767,788,546,290,806,63,704,81,272,340,56,770,245,840,569,112},
{594,391,145,503,570,846,144,74,630,496,937,269,881,417,315,447,785,762,285,682},
{665,255,471,353,839,108,292,75,189,94,730,186,189,465,676,59,913,148,98,782},
{205,932,128,132,865,704,101,186,578,597,189,549,594,467,89,234,341,670,354,570},
{292,310,549,420,578,837,353,625,441,107,435,84,122,339,98,945,669,641,358,590},
{468,925,610,202,865,661,783,675,216,936,253,745,985,609,544,395,938,770,435,89},
{778,925,572,701,307,292,213,745,87,398,343,903,100,271,569,156,394,622,144,23},
{622,765,433,417,590,69,57,112,205,214,780,480,299,398,79,140,883,552,636,556},
{753,806,287,877,138,82,309,133,195,212,552,583,222,621,196,412,501,635,461,472},
{351,113,743,705,86,671,834,783,405,107,427,617,494,878,270,905,129,411,637,674},
{84,478,628,880,69,435,107,659,634,696,543,771,228,286,312,191,64,926,557,283},
{627,441,419,160,160,99,857,700,104,838,693,538,316,53,281,758,591,407,436,460},
{838,928,882,154,744,881,584,132,765,157,141,519,729,199,905,686,351,729,88,625},
{819,636,880,339,201,56,131,145,835,137,364,213,572,193,905,208,677,399,763,69},
{452,537,171,271,361,79,613,575,222,880,944,937,659,201,555,780,146,56,434,941},
{542,860,620,57,595,627,362,272,273,152,106,739,554,614,73,630,944,210,684,74},
{871,745,903,352,73,675,311,688,354,933,837,147,168,417,396,593,667,806,641,507},
{144,417,159,87,929,395,928,938,547,311,735,616,278,751,266,84,465,752,362,996},
{357,626,555,80,903,743,584,441,101,659,357,753,191,977,574,224,614,429,701,557},
{252,55,776,569,672,762,130,743,688,939,790,93,128,632,845,9,740,199,339,927},
{665,317,468,670,943,949,289,881,550,68,348,757,402,315,176,354,81,109,458,203},
{348,547,179,463,304,660,544,119,157,281,307,18,704,555,248,50,309,95,784,808},
{184,596,86,134,804,554,144,430,583,182,565,613,627,180,929,355,705,507,198,778},
{608,315,471,116,391,948,186,752,668,479,772,572,787,636,742,209,501,477,949,15},
{99,191,768,357,431,833,181,468,496,622,586,437,678,89,283,934,63,479,128,411},
{126,773,202,660,544,359,764,82,251,156,51,580,884,208,559,545,684,703,900,611},
{74,842,327,279,539,57,452,428,108,221,278,191,576,538,72,697,882,117,701,732},
{753,925,688,560,576,497,835,221,152,665,925,550,191,183,486,292,767,282,390,154},
{497,816,749,274,685,419,509,536,280,575,139,783,903,86,839,206,207,883,428,740},
{358,766,668,120,808,425,220,596,693,882,691,597,603,703,160,495,681,846,638,311},
{840,575,571,266,470,790,666,310,244,588,669,101,934,935,553,945,133,622,307,852},
{149,636,112,685,862,440,672,187,699,730,740,671,839,255,941,676,73,779,222,364},
{595,776,502,582,574,184,356,629,626,596,475,622,468,570,753,822,866,780,927,392},
{942,560,761,54,477,764,211,674,52,391,850,630,109,660,677,52,901,946,587,927},
{597,735,230,417,472,211,93,127,807,614,163,762,662,741,305,216,663,581,363,212},
{292,915,475,509,732,699,138,866,243,676,419,731,905,419,391,462,697,751,199,838},
{939,452,993,462,311,547,93,285,358,734,440,457,97,926,430,90,740,776,672,615},
{192,112,625,633,276,487,463,777,698,837,927,609,343,271,152,345,669,219,936,157},
{563,392,358,947,51,345,767,782,220,404,52,878,345,266,460,469,576,364,741,204},
{674,543,948,97,14,666,186,308,685,477,103,765,149,290,573,555,214,737,97,865},
{175,835,844,397,674,253,149,547,835,596,441,597,544,143,95,589,701,839,200,743},
{934,107,225,834,107,210,538,223,671,841,314,300,676,421,880,418,552,672,366,787},
{843,932,731,115,155,930,630,405,95,899,272,670,557,927,597,947,361,460,165,867},
{630,131,759,143,58,767,136,162,342,61,188,596,607,750,742,948,637,842,819,402},
{81,407,155,247,872,360,492,211,76,868,133,738,201,637,280,640,845,479,433,114},
{549,355,155,884,941,577,745,582,621,72,109,536,96,777,979,673,152,944,588,198},
{202,214,910,77,209,112,341,691,546,688,286,679,660,315,743,597,540,705,255,419},
{368,757,846,560,454,441,875,82,317,705,106,560,339,745,496,506,422,497,555,476},
{197,417,195,190,72,285,837,120,593,688,595,683,900,558,499,346,779,664,627,328},
{409,247,105,551,685,472,458,704,74,194,92,537,687,774,665,944,345,843,629,254},
{463,629,665,426,108,554,998,426,79,162,903,537,905,219,315,219,541,804,752,695},
{568,402,777,215,480,145,901,342,765,185,730,558,743,834,856,278,780,553,595,555},
{456,404,939,343,592,360,808,693,674,541,104,163,315,676,768,752,424,398,331,405},
{905,362,545,631,60,752,103,491,689,398,803,202,698,393,187,351,313,431,479,617},
{702,349,941,316,414,426,315,402,697,188,549,496,630,432,839,343,404,660,701,393},
{452,841,681,745,872,472,440,190,694,84,942,64,566,940,662,781,468,131,875,217},
{670,467,353,356,563,836,454,607,59,567,770,50,901,748,275,927,429,506,554,501},
{852,61,586,933,667,416,352,757,729,902,284,286,934,72,428,843,579,309,930,505},
{522,243,933,311,118,495,426,554,729,539,69,765,703,184,747,218,185,455,741,899},
{160,188,466,250,755,360,104,170,186,686,354,193,273,670,636,108,391,212,835,225},
{52,694,122,546,475,868,342,346,182,767,671,946,478,929,575,150,350,284,865,465},
{642,995,473,315,778,55,929,770,590,638,777,77,142,594,733,355,699,288,150,75},
{606,255,684,89,269,567,949,417,875,184,359,691,852,435,421,879,883,838,146,627},
{156,757,462,112,842,462,348,479,412,346,352,903,629,477,732,343,536,762,425,94},
{128,50,878,206,459,404,141,456,148,280,306,677,711,65,698,620,219,498,681,555},
{306,748,830,899,637,743,304,629,589,181,665,461,582,194,463,58,775,162,138,739},
{474,485,114,134,456,684,759,73,63,452,540,573,557,578,939,941,613,152,540,191},
{839,55,942,279,149,615,574,360,277,687,432,578,732,991,151,306,762,636,431,880},
{198,267,50,637,194,426,807,760,787,537,768,538,490,696,204,767,593,471,934,432}
};
#endif

#if 0
std::vector<std::vector<int>> nearbyTickets = 
{
{3,9,18},
{15,1,5},
{5,14,9}
};
#endif

#if 1
size_t ticketInput[20] = 
{
79,67,101,89,131,107,139,113,127,83,137,53,71,149,73,97,59,61,109,103
};
#endif
#if 0
size_t ticketInput[3] = 
{
11,12,13
};
#endif

class Range
{
public:
    int min;
    int max;

    Range()
    {
        min = -1;
        max = -1;
    }

    Range(Range& other)
    {
        min = other.min;
        max = other.max;
    }
    Range(const Range& other)
    {
        min = other.min;
        max = other.max;
    }

    Range& operator=(Range& other)
    {
        min = other.min;
        max = other.max;
        return *this;
    }
    Range& operator=(const Range& other)
    {
        min = other.min;
        max = other.max;
        return *this;
    }
};

class RuleEntry
{
public:
    std::string name;
    Range ranges[2];

    RuleEntry()
    {
    }

    RuleEntry(RuleEntry& other)
    {
        name = other.name;
        ranges[0] = other.ranges[0];
        ranges[1] = other.ranges[1];
    }
    RuleEntry(const RuleEntry& other)
    {
        name = other.name;
        ranges[0] = other.ranges[0];
        ranges[1] = other.ranges[1];
    }

    RuleEntry& operator=(RuleEntry& other)
    {
        name = other.name;
        ranges[0] = other.ranges[0];
        ranges[1] = other.ranges[1];
        return *this;
    }
    RuleEntry& operator=(const RuleEntry& other)
    {
        name = other.name;
        ranges[0] = other.ranges[0];
        ranges[1] = other.ranges[1];
        return *this;
    }
    
};

static std::vector<RuleEntry> rules;
static inline void parseRuleLine(const char* line)
{
    RuleEntry rule;
    size_t i;
    char ruleName[50];
    int min1;
    int max1;
    int min2;
    int max2;
    for (i=0; line[i] != ':'; i++)
    {
        ruleName[i] = line[i];
    }
    ruleName[i] = '\0';
    i++; // skip the space
    sscanf(&line[i], "%d-%d or %d-%d", &min1, &max1, &min2, &max2);
    printf("Name, min1, max1, min2, max2: %s, %d, %d, %d, %d\n",
            ruleName, min1, max1, min2, max2);
    rule.name = std::string(ruleName);
    rule.ranges[0].min = min1;
    rule.ranges[0].max = max1;
    rule.ranges[1].min = min2;
    rule.ranges[1].max = max2;
    rules.push_back(rule);
}

static inline bool isValidVal(const int val)
{
    for (const RuleEntry& rule : rules)
    {
        if ((val >= rule.ranges[0].min &&
            val <= rule.ranges[0].max) ||
            (val >= rule.ranges[1].min &&
            val <= rule.ranges[1].max))
        {
            return true;
        }
    }
    return false;
}

static std::vector<size_t> validTicketIndices;

static inline void getRuleIndices(const size_t valIndex, std::vector<size_t>& resIndices)
{
    size_t i;
    size_t j;
    size_t resIndex = 0;
    
    for (j = 0; j < rules.size(); j++)
    {
        bool isValid = true;
        for (i = 0; i < validTicketIndices.size(); i++)
        {
            int val = nearbyTickets[validTicketIndices[i]][valIndex];
            isValid = (val >= rules[j].ranges[0].min &&
                       val <= rules[j].ranges[0].max) ||
                      (val >= rules[j].ranges[1].min &&
                       val <= rules[j].ranges[1].max);
            if (!isValid)
            {
                break;
            }
        }
        if (isValid)
        {
            resIndices.push_back(j);
        }
    }

    if (resIndices.size() == 0)
    {
        printf("ERROR - FAILED TO FIND RULE INDEX!\n");
    }
}

std::vector<std::vector<size_t>> totalValidRuleIndices;
static inline void printTotalValidRuleIndices()
{
    for (auto& ruleList : totalValidRuleIndices)
    {
        printf("PossibleRule: ");
        for (auto& ruleVal : ruleList)
        {
            printf("%lu, ", ruleVal);
        }
        printf("\n");
    }
}

std::vector<int> foundIndices;
static bool reduceTotalValidRuleIndices()
{
    // find the row with a single entry and its value
    size_t singleRow;
    size_t singleVal;
    size_t i;
    size_t j;
    for (i = 0; i < totalValidRuleIndices.size(); i++)
    {
        if (totalValidRuleIndices[i].size() == 1)
        {
            if (std::find(foundIndices.begin(),
                          foundIndices.end(),
                          totalValidRuleIndices[i][0]) == 
                foundIndices.end())
            {
                singleRow = i;
                singleVal = totalValidRuleIndices[i][0];
                foundIndices.push_back(singleVal);
                break;
            }
        }
    }
    if (i == totalValidRuleIndices.size())
    {
        // not able to reduce
        return false;
    }
    for (i = 0; i < totalValidRuleIndices.size(); i++)
    {
        if (i == singleRow)
        {
            continue;
        }
        auto index = std::find(totalValidRuleIndices[i].begin(),
                               totalValidRuleIndices[i].end(),
                               singleVal);
        if (index != totalValidRuleIndices[i].end())
        {
            totalValidRuleIndices[i].erase(index);
        }
    }
    return true;
}

int main(void)
{
    unsigned long long invalidSum = 0;
    size_t i;
    size_t j;
    for (i = 0; i < RULES_LEN; i++)
    {
        parseRuleLine(rulesInput[i]);
    }
    for (size_t i = 0; i < nearbyTickets.size(); i++)
    {
        bool ticketIsValid = true;
        for (const int val : nearbyTickets[i])
        {
            if (!isValidVal(val))
            {
                ticketIsValid = false;
                break;
            }
        }
        if (ticketIsValid)
        {
            validTicketIndices.push_back(i);
        }
    }
    printf("Valid ticket indices size: %lu\n", validTicketIndices.size());

    for (i = 0; i < nearbyTickets[0].size(); i++)
    {
        std::vector<size_t> validIndices;
        getRuleIndices(i, validIndices);
        totalValidRuleIndices.push_back(validIndices);
    }

    do
    {
        printf("Before reduction:\n");
        printTotalValidRuleIndices();
    } while (reduceTotalValidRuleIndices());

    // get the values from the input for each "departs"
    // (the first 6 rules)
    unsigned long long product = 1;
    for (i = 0; i < 6; i++)
    {
        size_t ticketIndex = 0;
        for (j = 0; j < totalValidRuleIndices.size(); j++)
        {
            if (totalValidRuleIndices[j][0] == i)
            {
                ticketIndex = j;
            }
        }
        printf("Ticket index, val: %lu, %d\n", ticketIndex,
                                               ticketInput[ticketIndex]);
        product *= ticketInput[ticketIndex];
    }
    printf("Product: %llu\n", product);
    return 0;
}

