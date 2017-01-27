#!/bin/bash

DB='/home-1/class-2@jhu.edu/db/chinook.db'

echo Database:
sqlite3 $DB ".database"
echo

echo Tables:
sqlite3 $DB ".tables"
echo

echo Table schema:
sqlite3 $DB ".schema albums"
sqlite3 $DB ".schema artists"
echo

echo Query:
sqlite3 $DB "SELECT * FROM artists;"
echo
sqlite3 $DB "SELECT * FROM artists
  WHERE name
  LIKE 'R%';"
echo
sqlite3 $DB "SELECT title FROM albums
  ORDER BY title
  LIMIT 10;"
echo

echo Join:
sqlite3 $DB "SELECT trackid, name, title
  FROM tracks
  INNER JOIN albums
  ON albums.albumid = tracks.albumid
  LIMIT 10;"
echo

echo Join more:
sqlite3 $DB "SELECT trackid,
    tracks.name,
    albums.title,
    artists.name
  FROM
    tracks
  INNER JOIN albums
  ON albums.albumid = tracks.albumid
  INNER JOIN artists
  ON artists.artistid = albums.artistid
  LIMIT 10;"
