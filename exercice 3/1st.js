var array = [10,5,13,18,51];

console.log("1 zadacha :")
    function first(array)
    {
        for(const index in array)
        {
            console.log(array[index]);
        }

    }
    first(array);

console.log("2 zadacha :");
    function second(array)
    {
        var array2 = new Array;
        for(const index in array)
        {
            array2[index] = array[index]*2;
        }
        return array2;
    }
    console.log( second(array));

console.log("3 zadacha :");
    function third(array)
    {
        let helper = array.map((num) => {
            if(num % 3 == 0) {
                console.log(num);     
            }
         })
    }
    third(array);
console.log("4 zadacha :");
    function fourth(array)
    {
        for(const index in array)
        {
            if(array[index] < 10)
            {
                return true;
            }
        }
        return false;
    }
    console.log(fourth(second(array)));
    
console.log("5 zadacha :");
    function fifth(array)
    {
        
        var array2 = new Array;
        for(const index in array)
        {
            if(array[index] %3 == 0)
            {
                array2.push(array[index]);
            }
        }
        return array2;
    }
    console.log(fifth(array));

console.log("6 zadacha :");
    const reducer = (accumulator, currentValue) => accumulator + currentValue;
    console.log(array.reduce(reducer));

console.log("7 zadacha :");
    function seventh(array)
    {
        let array2 = new Array;
        array2 = array.slice(3);
        return array2;
    }
    console.log(seventh(array));