import React, { useState } from "react";
import "./App.css";
import InputArea from "./components/InputArea";
import ToDoItem from "./components/ToDoItem";

function App() {
  const [items, setItems] = useState([]);

  function addItem(item) {
    setItems([...items, item]);
  }

  function deleteItem(index) {
    const updatedItems = items.filter((_, i) => i !== index);
    setItems(updatedItems);
  }

  return (
    <div className="App">
      <div className="ToDoList">
        <h1>To-Do List</h1>
        <InputArea addItem={addItem} />
        <ul>
          {items.map((item, index) => (
            <ToDoItem
              key={index}
              item={item}
              index={index}
              deleteItem={deleteItem}
            />
          ))}
        </ul>
      </div>
    </div>
  );
}
export default App;
