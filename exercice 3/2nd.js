var dates = new Array();

var currentDate = new Date();
dates.push(currentDate);
var newDate = new Date;
newDate.setDate(8);
newDate.setMonth(11);
newDate.setFullYear(2018);
newDate.setHours(21,00,00);
dates.push(newDate);
console.log(dates);


var daysInMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
for(const index in dates)
{
    console.log(daysInMonth[dates[index].getMonth()]) 
}