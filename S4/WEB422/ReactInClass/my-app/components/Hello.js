export default function Hello(props) {
  let hello = "Hello World from component!";
  return (
    <>
      {hello.toUpperCase}
      {props.text.toUpperCase()}
      <hr />
      <img src={props.img} alt="placeholder" />
    </>
  );
}

Hello.defaultProps = {
  text: "Add text prop",
  img: "https://via.placeholder.com/150?text=Not+available",
};
