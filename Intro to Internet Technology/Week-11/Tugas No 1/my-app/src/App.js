import React, { useState } from "react";
import "./style.css";


function App(){

  const [state, change] = useState(1);
  function increase() {
    change(state + 1);
  }

  function decrease() {
    change(state - 1);
  }

  return (
    <div className="App">
      <h1>{state}</h1>
      <button onClick={increase} className="btn">
        <b>Increase (+)</b>
      </button>
      <button onClick={decrease} className="btn">
        <b>Decrease (-)</b>
    </button>
    </div>
    );
  }
export default App;