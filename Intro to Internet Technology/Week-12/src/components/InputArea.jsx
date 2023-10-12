import React, { useState } from "react";

function InputArea({ addItem }) {
    const [inputValue, setInputValue] = useState("");

function handleChange(event) {
    setInputValue(event.target.value);
}

function handleSubmit(event) {
    event.preventDefault();
    if (inputValue !== "") {
        addItem(inputValue);
        setInputValue("");
    }
}

return (
    <form onSubmit={handleSubmit}>
        <input
            type="text"
            placeholder=""
            value={inputValue}
            onChange={handleChange}
        />
        <button type="submit">Add</button>
    </form>
    );
}

export default InputArea;
