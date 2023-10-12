import React from "react";

function ToDoItem({ item, index, deleteItem }) {
    function handleClick() {
        deleteItem(index);
    }

    return <li onClick={handleClick}>{item}</li>;
}

export default ToDoItem;
