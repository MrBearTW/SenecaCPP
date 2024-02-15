import React, {useState} from 'react';

export default function ClickCounter({start}){

    const [numClicks, setNumClicks] = useState(start)

    function handleClick(event){
        setNumClicks(numClicks + 1)
    } 

    return (
        <>
            <button onClick={handleClick}>Clicked {numClicks} times</button>
        </>
    )
}

ClickCounter.defaultProps = {
    start: 0
}