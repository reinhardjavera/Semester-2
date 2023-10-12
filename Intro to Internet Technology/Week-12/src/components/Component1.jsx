import { useState } from "react";

export default function Components1(props) {
    const [inputText, setInputText] = useState("");

function handleChange(event) {
    const newValue = event.target.value;
    setInputText(newValue);
}

    return (
        <div>
            <input onChange={handleChange} type="text" value={inputText}></input>
            <button
                onClick={() => {
                props.onSubmit(inputText);
                setInputText("");
                }}
            >
                Submit
            </button>
        </div>
    );
}
