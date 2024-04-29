const allMovies = document.getElementById("allMovies");
const main = document.main;
const plusButton = document.querySelector(".plusButton");
const bodyElement = document.body;
const form = document.getElementById("form");
const search = document.getElementById("query");
const apiKey = "c258ba6e10c34551d299688b1f72451b";
const language = "fr";
let page_num = 1;
let new_page = 5;
let movieSection;
let genreId;
let searchItem;
let periode = "week";
let whichToCharge;

const trendUrl = "https://api.themoviedb.org/3/trending/movie/week?language=fr";
const discoverUrl = "https://api.themoviedb.org/3/discover/movie";
const baseUrl = "https://api.themoviedb.org/3/movie/";
const SearchApi = `https://api.themoviedb.org/3/search/movie?api_key=${apiKey}&language=${language}`;
const img_path = "https://image.tmdb.org/t/p/w1280";
const genreListUrl = "https://api.themoviedb.org/3/genre/movie/list";

createAccueil();

// _______________________________________________________________________________________
// --------------------- PERMET DE GENERER DES DIV----------------------------------------
function createDiv(div_class) {
  const newDiv = document.createElement("div");
  newDiv.setAttribute("class", div_class);
  return newDiv;
}
function createSection(sect_class, sect_id) {
  const newSect = document.createElement("section");
  newSect.setAttribute("class", sect_class);
  newSect.setAttribute("id", sect_id);
  return newSect;
}

function createDivID(SectionID) {
  const newDiv = document.createElement("div");
  newDiv.setAttribute("class", "MoviesContener");
  newDiv.setAttribute("id", SectionID);
  return newDiv;
}

// ____________________________________________________________________________________________________
// -----------------------RECUPERE LES DETAILS DES FILMS-----------------------------------------------
function getDetail(url, div, callback) {
  fetch(url)
    .then((response) => response.json())
    .then(function (data) {
      const rating = document.createElement("p");
      rating.innerHTML = `Note: ${data.vote_average}`;
      const releaseDate = document.createElement("p");
      releaseDate.innerHTML = `Sortie: ${data.release_date}`;
      const duration = document.createElement("p");
      duration.innerHTML = `Durée: ${data.runtime} minutes`;
      const genre = document.createElement("p");
      if (Array.isArray(data.genres) && data.genres.length > 0) {
        const genreNames = data.genres.map((genre) => genre.name);
        genre.innerHTML = `Genre: ${genreNames.join(", ")}`;
      } else {
        genre.innerHTML = "Genre: N/A";
      }
      div.appendChild(rating);
      div.appendChild(releaseDate);
      div.appendChild(duration);
      div.appendChild(genre);

      callback();
    });
}

// _____________________________________________________________________________________________________
// --------------------------GESTION DES RECHERCHES---------------------------------------------------
form.addEventListener("input", handleInput);
function handleInput() {
  allMovies.innerHTML = "";
  whichToCharge = 0;
  toggleChargeButton();
  console.log(whichToCharge);
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  searchItem = search.value;
  let searching = document.createElement("h1");
  searching.setAttribute("class", "recherce");
  searching.innerHTML = "Résultats pour : " + searchItem;
  div_fullPage.appendChild(searching);
  if (searchItem) {
    allMovies.innerHTML = "";
    const encodedSearchTerm = encodeURIComponent(searchItem);
    const searchUrl = `${SearchApi}&query=${encodedSearchTerm}`;
    returnMovie(searchUrl, div_fullPage, sect_fullPage);
  }
  if (!searchItem) {
    createAccueil();
  }
}

function ActionMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 28;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function AventureMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 12;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function AnimationMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 16;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function ComedieMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 35;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function CrimeMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 80;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function DocumentaireMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 99;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function DrameMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 18;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function FamilialMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 10751;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function FantastiqueMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 14;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function HistoriqueMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 36;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function HorreurMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 27;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function MusicalMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 10402;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function MystereMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 9648;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function RomanceMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 10749;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function SFMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 878;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function TVMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 10770;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function ThrillerMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 53;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function GuerreMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 10752;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function WesternMovies() {
  new_page = 5;
  page_num = 1;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  allMovies.innerHTML = "";
  genreId = 37;
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function MoviesByGenre(sect, div) {
  whichToCharge = 1;
  toggleChargeButton();
  console.log("whichToCharge " + whichToCharge);
  for (page_num; page_num <= new_page; page_num++) {
    let MoviesByGenreUrl = `${discoverUrl}?api_key=${apiKey}&language=${language}&sort_by=popularity.desc&with_genres=${genreId}&page=${page_num}`;
    returnMovie(MoviesByGenreUrl, div, sect);
  }
}

//_____________________________________________________________________________________________________
//-----------------------FCT POUR CHARGER + DE PAGE--------------------------------------------------
function chargeMore() {
  new_page = new_page + 5;
  const sect_fullPage = createDivID("sec_fullPage");
  const div_fullPage = createSection("div_fullpage");
  console.log("genre id :" + genreId);
  MoviesByGenre(sect_fullPage, div_fullPage);
}

function toggleChargeButton() {
  if (whichToCharge == 1) {
    plusButton.style.display = "block";
  } else {
    plusButton.style.display = "none";
  }
}

//-----------------------FCT POUR CHARGER + DE PAGE--------------------------------------------------
//_____________________________________________________________________________________________________

//_____________________________________________________________________________________________________
//-----------------------CREATION AFICHAGE FILMS SIMILAIRE--------------------------------------------------
function displaySimilarMovie(similarMovie, container) {
  const div_card = createDiv("card");
  const div_image = createDiv("thumbnail");

  const detailURL = `${baseUrl}${similarMovie.id}?api_key=${apiKey}&language=${language}`;
  div_image.addEventListener("click", showDetail.bind(null, detailURL));

  if (similarMovie.poster_path !== null) {
    div_image.style.backgroundImage = `url(${
      img_path + similarMovie.poster_path
    })`;
  } else {
    div_image.style.backgroundImage = "url(./img/Spongebob.png)";
  }
  div_image.style.backgroundSize = "cover";

  const div_title = createDiv("div_title");
  const title = document.createElement("h3");
  title.setAttribute("id", "title");
  title.innerHTML = `${similarMovie.title}`;

  let div_details = createDiv("infos");
  div_details.style.display = "none";
  container.appendChild(div_card);
  div_card.appendChild(div_image);
  div_image.appendChild(div_details);
  div_card.appendChild(div_title);
  div_title.appendChild(title);

  getDetail(detailURL, div_details, () => {
    div_image.addEventListener("mouseover", () => {
      div_details.style.display = "block";
    });

    div_image.addEventListener("mouseout", () => {
      div_details.style.display = "none";
    });
  });
}

/// ____________________________________________________________________________________________________________________
// --------------------------RECUPERE LES DONNEE SUR LES FILM SIMILAIRES---------------------------------------------------
function showSimilarMovies(url) {
  fetch(url)
    .then((response) => response.json())
    .then(function (data) {
      const div_similarMovies = createDiv("similarMovies");

      data.results.forEach((similarMovie) => {
        displaySimilarMovie(similarMovie, div_similarMovies);
      });

      allMovies.appendChild(div_similarMovies);
    });
}

// ____________________________________________________________________________________
// ----------------RECUPERATIONS DONNES D'UN FILM ET AFFICHAGE----------------------------
function showDetail(url) {
  whichToCharge = 0;
  toggleChargeButton();
  allMovies.innerHTML = "";
  fetch(url)
    .then((response) => response.json())
    .then(function (data) {
      const div_specificMovie = createDiv("specificMovie");
      const div_firstInfo = createDiv("firstInfo");
      const div_firstText = createDiv("firstText");
      const MovieImage = document.createElement("img");
      MovieImage.setAttribute("class", "movieImage");
      if (data.poster_path !== null) {
        MovieImage.src = `${img_path + data.poster_path}`;
      } else {
        MovieImage.src = "./img/Spongebob.png";
      }
      MovieImage.style.backgroundSize = "cover";

      const Title = document.createElement("h1");
      Title.setAttribute("class", "contenu");
      Title.innerHTML = `${data.title}`;

      const tagline = document.createElement("p");
      tagline.setAttribute("class", "contenu");
      tagline.setAttribute("id", "tagline");
      tagline.innerHTML = `${data.tagline}`;

      const prompt = document.createElement("p");
      prompt.setAttribute("class", "contenu");
      prompt.innerHTML = `${data.overview}`;

      const MovieDate = document.createElement("p");
      MovieDate.setAttribute("class", "contenu");
      MovieDate.innerHTML = `Date de sortie : ${data.release_date}`;

      const MovieNote = document.createElement("p");
      MovieNote.setAttribute("class", "contenu");
      MovieNote.innerHTML = `Note : ${data.vote_average}`;

      const MovieGenre = document.createElement("p");
      MovieGenre.setAttribute("class", "contenu");
      if (Array.isArray(data.genres) && data.genres.length > 0) {
        const MovieGenreNames = data.genres.map((genre) => genre.name);
        MovieGenre.innerHTML = `Genre : ${MovieGenreNames.join(", ")}`;
      } else {
        genre.innerHTML = "Genre: N/A";
      }
      let movieID = `${data.id}`;
      let SimilarMovielURL = `${baseUrl}${movieID}/similar?api_key=${apiKey}&language=${language}`;
      const div_similarMovies = createDiv("similarMovies");
      showSimilarMovies(SimilarMovielURL, div_similarMovies);

      allMovies.appendChild(div_specificMovie);
      div_specificMovie.appendChild(div_firstInfo);
      div_firstInfo.appendChild(MovieImage);
      div_firstInfo.appendChild(div_firstText);
      div_firstText.appendChild(Title);
      div_firstText.appendChild(tagline);
      div_firstText.appendChild(MovieGenre);
      div_firstText.appendChild(MovieNote);
      div_firstText.appendChild(prompt);
      div_firstText.appendChild(MovieDate);
    });
}

// --------------------------AFFICHAGE DES FILMS SEULS---------------------------------------------------
/// _____________________________________________________________________________________________________
/// _____________________________________________________________________________________________________

// ______________________________________________________________________________________________
// --------------------------------AFFICHE LES FILMS---------------------------------------------
function displayMovie(movie, div, section) {
  let movieID = `${movie.id}`;
  let detailURL = `${baseUrl}${movieID}?api_key=${apiKey}&language=${language}`;
  const div_card = createDiv("card");
  const div_image = createDiv("thumbnail");
  div_image.addEventListener("click", showDetail.bind(null, detailURL));

  if (movie.poster_path !== null) {
    div_image.style.backgroundImage = `url(${img_path + movie.poster_path})`;
  } else {
    div_image.style.backgroundImage = "url(./img/Spongebob.png)";
  }
  div_image.style.backgroundSize = "cover";

  const div_title = createDiv("div_title");
  const title = document.createElement("h3");
  title.setAttribute("id", "title");
  title.innerHTML = `${movie.title}`;

  // --------------------CREE ZONE AFFICHAGE ET ORGANISE DOM--------------------------------

  let div_details = createDiv("infos");
  div_details.style.display = "none";

  allMovies.appendChild(div);
  div.appendChild(section);
  section.appendChild(div_card);
  div_card.appendChild(div_image);
  div_image.appendChild(div_details);
  div_card.appendChild(div_title);
  div_title.appendChild(title);

  getDetail(detailURL, div_details, () => {
    div_image.addEventListener("mouseover", () => {
      div_details.style.display = "block";
    });

    div_image.addEventListener("mouseout", () => {
      div_details.style.display = "none";
    });
  });
}

// ______________________________________________________________________________________________________
// ------------------RECUPERE LES INFOS SUR BCP DE FILMS---------------------------------------------------
function returnMovie(url, div, section) {
  fetch(url)
    .then((res) => res.json())
    .then(function (data) {
      if (data.results == 0) {
        const error_message = document.createElement("h3");
        error_message.setAttribute("class", "errorMessage");
        error_message.innerHTML = "Aucun films trouvé pour :  " + searchItem;
        allMovies.appendChild(error_message);
      }
      data.results.forEach((element) => {
        displayMovie(element, div, section);
      });
    });
}

// __________________________________________________________________________________
// ----------------- FONCTION POUR MODIFIER QUEL LIEN ON VA CHERCHER------------------
function getURL(apiKey, page_num, language, movieSection) {
  let endpoint;
  switch (movieSection) {
    case "En ce moment :":
      endpoint = "now_playing";
      break;
    case "Les mieux noté :":
      endpoint = "top_rated";
      break;
    case "Les plus populaires :":
      endpoint = "popular";
      break;
    case "À venir :":
      endpoint = "upcoming";
      break;
    case "Les dernières sorties :":
      endpoint = "latest";
      break;
  }
  let url = `${baseUrl}${endpoint}?api_key=${apiKey}&page=${page_num}&language=${language}`;
  console.log(url);
  return url;
}

// _______________________________________________________________________________________
// --------------------- PERMET DE GENERER DES PAGES--------------------------------------
function firstChargement(movieSection, div, section) {
  toggleChargeButton();
  console.log("hih");
  for (page_num; page_num <= new_page; page_num++) {
    let url = getURL(apiKey, page_num, language, movieSection);
    console.log(url);
    returnMovie(url, div, section);
  }
}

// --------------------- PAGE D'ACCUEIL-------------------------------------
// _______________________________________________________________________________________

function popMovie(ID, CLASS, TITRE) {
  const sect_popularite = createSection(CLASS, "movies_by_popularite");
  const div_popularite = createDivID(ID);
  new_page = 5;
  page_num = 1;
  movieSection = "Les mieux noté :";
  let sectTitle = document.createElement("h1");
  sectTitle.setAttribute("class", "titreDeTri");
  let more = document.createElement("p");
  more.innerHTML = ">Cliquez ici pour en voir plus<";
  more.setAttribute("class", "moreLink");
  sectTitle.innerHTML = TITRE;
  sect_popularite.appendChild(sectTitle);
  sect_popularite.appendChild(more);
  more.addEventListener("click", () => {
    new_page = 20;
    page_num = 1;
    movieSection = "Les mieux noté :";
    const sect_moviesByX = createSection("sect_moviesByX");
    const div_moviesByX = createDivID("div_moviesByX");
    firstChargement(movieSection, sect_moviesByX, div_moviesByX);
    bodyElement.addEventListener("click", () => {
      sect_moviesByX.remove();
      toggleChargeButton();
    });
  });
  firstChargement(movieSection, sect_popularite, div_popularite);
  return sect_popularite;
}

function noteMovie(ID, CLASS, TITRE) {
  const sect_mieuxNote = createSection(CLASS, "movies_by_notes");
  const div_mieuxNote = createDivID(ID);
  new_page = 5;
  page_num = 1;
  movieSection = "Les plus populaires :";
  sectTitle = document.createElement("h1");
  sectTitle.setAttribute("class", "titreDeTri");
  let more = document.createElement("p");
  more.innerHTML = ">Cliquez ici pour en voir plus<";
  more.setAttribute("class", "moreLink");
  sectTitle.innerHTML = TITRE;
  sect_mieuxNote.appendChild(sectTitle);
  sect_mieuxNote.appendChild(more);
  more.addEventListener("click", () => {
    new_page = 20;
    page_num = 1;
    movieSection = "Les plus populaires :";
    const sect_moviesByX = createSection("sect_moviesByX");
    const div_moviesByX = createDivID("div_moviesByX");
    firstChargement(movieSection, sect_moviesByX, div_moviesByX);
    bodyElement.addEventListener("click", () => {
      sect_moviesByX.remove();
      toggleChargeButton();
    });
  });
  firstChargement(movieSection, sect_mieuxNote, div_mieuxNote);
  return sect_mieuxNote;
}

function nowMovie(ID, CLASS, TITRE) {
  const sect_mtn = createSection(CLASS, "movies_by_now");
  const div_mtn = createDivID(ID);
  new_page = 5;
  page_num = 1;
  movieSection = "En ce moment :";
  sectTitle = document.createElement("h1");
  sectTitle.setAttribute("class", "titreDeTri");
  let more = document.createElement("p");
  more.innerHTML = ">Cliquez ici pour en voir plus<";
  more.setAttribute("class", "moreLink");
  sectTitle.innerHTML = TITRE;
  sect_mtn.appendChild(sectTitle);
  sect_mtn.appendChild(more);
  more.addEventListener("click", () => {
    new_page = 20;
    page_num = 1;
    movieSection = "En ce moment :";
    const sect_moviesByX = createSection("sect_moviesByX");
    const div_moviesByX = createDivID("div_moviesByX");
    firstChargement(movieSection, sect_moviesByX, div_moviesByX);
    bodyElement.addEventListener("click", () => {
      sect_moviesByX.remove();
      toggleChargeButton();
    });
  });
  firstChargement(movieSection, sect_mtn, div_mtn);
  return sect_mtn;
}

function toComeMovie(ID, CLASS, TITRE) {
  const sect_upcoming = createSection(CLASS, "movies_by_coming");
  const div_upcoming = createDivID(ID);
  new_page = 5;
  page_num = 1;
  movieSection = "À venir :";
  sectTitle = document.createElement("h1");
  sectTitle.setAttribute("class", "titreDeTri");
  let more = document.createElement("p");
  more.innerHTML = ">Cliquez ici pour en voir plus<";
  more.setAttribute("class", "moreLink");
  sectTitle.innerHTML = TITRE;
  sect_upcoming.appendChild(sectTitle);
  sect_upcoming.appendChild(more);
  more.addEventListener("click", () => {
    morege = 20;
    page_num = 1;
    movieSection = "À venir :";
    const sect_moviesByX = createSection("sect_moviesByX");
    const div_moviesByX = createDivID("div_moviesByX");
    firstChargement(movieSection, sect_moviesByX, div_moviesByX);
    bodyElement.addEventListener("click", () => {
      sect_moviesByX.remove();
      plusButton.style.position = "absolute";
      toggleChargeButton();
    });
  });
  firstChargement(movieSection, sect_upcoming, div_upcoming);
  return sect_upcoming;
}

function chosedOne(div, url) {
  const div_TrendyInf = createDiv("MovieInformations");
  fetch(url)
    .then((response) => response.json())
    .then(function (data) {
      if (data.poster_path !== null) {
        div.style.backgroundImage = `url(${img_path + data.poster_path})`;
      } else {
        div.src = "./img/Spongebob.png";
      }

      const Title = document.createElement("h1");
      Title.setAttribute("class", "contenu");
      Title.innerHTML = `${data.title}`;
      let movieID = `${data.id}`;
      let detailURL = `${baseUrl}${movieID}?api_key=${apiKey}&language=${language}`;
      Title.addEventListener("click", showDetail.bind(null, detailURL));

      const tagline = document.createElement("p");
      tagline.setAttribute("class", "contenu");
      tagline.setAttribute("id", "tagline");
      tagline.innerHTML = `${data.tagline}`;

      const prompt = document.createElement("p");
      prompt.setAttribute("class", "contenu");
      prompt.innerHTML = `${data.overview}`;

      const MovieDate = document.createElement("p");
      MovieDate.setAttribute("class", "contenu");
      MovieDate.innerHTML = `Date de sortie : ${data.release_date}`;

      const MovieNote = document.createElement("p");
      MovieNote.setAttribute("class", "contenu");
      MovieNote.innerHTML = `Note : ${data.vote_average}`;

      const MovieGenre = document.createElement("p");
      MovieGenre.setAttribute("class", "contenu");
      if (Array.isArray(data.genres) && data.genres.length > 0) {
        const MovieGenreNames = data.genres.map((genre) => genre.name);
        MovieGenre.innerHTML = `Genre : ${MovieGenreNames.join(", ")}`;
      } else {
        genre.innerHTML = "Genre: N/A";
      }

      div.appendChild(div_TrendyInf);
      div_TrendyInf.appendChild(Title);
      div_TrendyInf.appendChild(tagline);
      div_TrendyInf.appendChild(MovieGenre);
      div_TrendyInf.appendChild(MovieNote);
      div_TrendyInf.appendChild(prompt);
      div_TrendyInf.appendChild(MovieDate);
    });
  return div;
}

function redoit(id) {
  return function () {
    const section = document.getElementById("accueil");
    section.innerHTML = "";
    tendance(id);
  };
}

function displayTendances(ID, movie, div) {
  if (movie.id != ID) {
    const div_propal = createDiv("propal");
    div_propal.setAttribute("class", "thumbnail");
    let ID = movie.id;
    div_propal.addEventListener("click", redoit(ID));
    if (movie.poster_path !== null) {
      div_propal.style.backgroundImage = `url(${img_path + movie.poster_path})`;
    } else {
      div_propal.style.backgroundImage = "url(./img/Spongebob.png)";
    }
    div_propal.style.backgroundSize = "cover";
    div.appendChild(div_propal);
    return div;
  }
}

function tendance(selectedID) {
  const sect_accueil = document.getElementById("accueil");
  const sect_tendance = createSection("sect_tendance", "movie_by_tendance");
  const div_chosenOne = createDiv("biggest");
  let selectedURL = `${baseUrl}${selectedID}?api_key=${apiKey}&language=${language}`;
  chosedOne(div_chosenOne, selectedURL);
  const trendTitle = document.createElement("h1");
  const div_trendyToo = createDivID("trendyToo");
  trendTitle.innerHTML = "Les tendances de la semaine :";
  sect_accueil.appendChild(sect_tendance);
  sect_tendance.appendChild(trendTitle);
  sect_tendance.appendChild(div_chosenOne);
  sect_tendance.appendChild(div_trendyToo);

  let url = `https://api.themoviedb.org/3/trending/movie/${periode}?language=${language}&api_key=${apiKey}`;
  fetch(url)
    .then((res) => res.json())
    .then(function (data) {
      data.results.forEach((element) => {
        displayTendances(selectedID, element, div_trendyToo, div_chosenOne);
      });
    });
  div_chosenOne.appendChild(div_trendyToo);
}

function randomizeTendance() {
  console.log(periode);
  const url = `https://api.themoviedb.org/3/trending/movie/${periode}?language=${language}&api_key=${apiKey}`;
  return fetch(url)
    .then((res) => res.json())
    .then(function (data) {
      const random = Math.floor(Math.random() * data.results.length);
      const chosenOne = data.results[random];
      const selectedID = chosenOne.id;
      tendance(selectedID);
    });
}

function createAccueil() {
  whichToCharge = 0;
  toggleChargeButton();
  allMovies.innerHTML = "";
  const sect_accueil = createSection("accueil", "accueil");
  allMovies.appendChild(sect_accueil);
  randomizeTendance();
  popMovie("popularity", "Filmclassement", "Les mieux noté :");
  nowMovie("EnCeMoment", "Filmclassement", "En ce moment :");
  toComeMovie(
    "upcoming",
    "Filmclassement",
    "Les dernières et futures sorties :"
  );
  noteMovie("mieuxNote", "Filmclassement", "Les plus populaires :");
}
