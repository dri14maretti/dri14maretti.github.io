"use strict";

const buttonContainer = document.querySelector(".three-line-button");

buttonContainer.addEventListener("click", function (e) {
	e.preventDefault();

	console.log("clicked");
});
