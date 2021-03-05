"use strict";

const navContainer = document.querySelector(".navigation");
const buttonContainer = document.querySelector(".three-line-button");
const listContainer = document.querySelector(".menujs");
const listLiContainer = document.querySelector(".menujs li");

buttonContainer.addEventListener("click", function (e) {
	e.preventDefault();

	if (navContainer.className === "navigation") {
		navContainer.className += " menujs";
		buttonContainer.innerHTML = "&Cross;";
	} else {
		navContainer.className = "navigation";
		buttonContainer.innerHTML = "&#9776;";
	}
});
