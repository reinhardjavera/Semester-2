import React from "react";
import ReactDOM from "react-dom/client";
import "./index.css";
import Heading from "./components/Heading";
import Cards from "./components/Card";
import contacts from "./components/Contact";

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(
  <React.StrictMode>
    <div className="container">
      <Heading />
      <div>
        <Cards
          imgURL={contacts[0].imgURL}
          name={contacts[0].name}
          phone={contacts[0].phone}
          email={contacts[0].email}
        />
      </div>
      <div>
        <Cards
          imgURL={contacts[1].imgURL}
          name={contacts[1].name}
          phone={contacts[1].phone}
          email={contacts[1].email}
        />
      </div>
      <div>
        <Cards
          imgURL={contacts[2].imgURL}
          name={contacts[2].name}
          phone={contacts[2].phone}
          email={contacts[2].email}
        />
      </div>
    </div>
  </React.StrictMode>
);
