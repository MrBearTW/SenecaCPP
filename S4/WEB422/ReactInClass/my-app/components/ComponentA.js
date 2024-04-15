import ComponentB from "./ComponentB";

export default function ComponentA(){
    console.log("Rendering ComponentA");
    return (<>
        <ComponentB  />
    </>);
}