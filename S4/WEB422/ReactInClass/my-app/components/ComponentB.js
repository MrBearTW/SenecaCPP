import ComponentC from "./ComponentC";

export default function ComponentB(){
    console.log("Rendering ComponentB");
    return (<>
        <ComponentC />
    </>);
}