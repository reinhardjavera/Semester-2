import React from "react";
import ReactDOM from "react-dom/client";
import "./index.css";
import Heading from "./components/heading";
import Card from "./components/card";
import emojipedia from "./components/emojipedia"

function printCards(x, item) {
  return <Card id={x.id} emoji={x.emoji} name={x.name} meaning={x.meaning} />;
}

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(
  <div className="container">
    <Heading />
    {emojipedia.map(printCards)}
  </div>
);