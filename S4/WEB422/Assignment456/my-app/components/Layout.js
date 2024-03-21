import React from "react";
import MainNav from "./MainNav";
import Container from "react-bootstrap/Container";

export default function Layout(props) {
  return (
    <>
      <div>
        <MainNav />
        <br />
        <Container>{props.children}</Container>
        <br />
      </div>
    </>
  );
}
