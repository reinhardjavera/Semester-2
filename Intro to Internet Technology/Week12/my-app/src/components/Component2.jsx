import React from "react";

export default function Components2(props) {
    return (
        <li
            onClick={() => {
                props.onClick(props.id);
            }}
        >
            {props.text}
        </li>
    );
}
