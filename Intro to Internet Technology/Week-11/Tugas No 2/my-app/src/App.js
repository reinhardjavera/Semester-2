import React, { useState } from "react";
import './style.css';

function App() {
  const [time, setTime] = useState("Time");

  function getTime() {
    const timeNow = new Date().toLocaleTimeString();
    setTime(timeNow);
  }

  return (
    <div className="App">
      <div className="content">
        <h1>{time}</h1>
        <div className="btn">
          <button onClick={getTime}>Get Time</button>
        </div>
      </div>
    </div>
  );
}

export default App;