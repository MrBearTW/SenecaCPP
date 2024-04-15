import { useAtom } from "jotai";
import { countAtom } from "@/store";

export default function ComponentC(){
    console.log("Rendering ComponentC");

    const [count, setCount] = useAtom(countAtom);

    function handleClick(){
       console.log("handle click");
       setCount(count + 1);
    }

    return (<>
        <button onClick={handleClick}>Increment Count</button>
    </>);
}