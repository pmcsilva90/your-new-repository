--Select players.first_name, players.last_name, salaries.salary, performances.hr from

--select * from
--players join salaries on player.id = salaries.player_id

SELECT
    players.first_name,
    players.last_name,
    salaries.salary,
    salaries.year,
    performances.year,
    performances.HR
FROM
    players
    JOIN salaries ON players.id = salaries.player_id
    JOIN performances ON salaries.player_id = performances.player_id AND salaries.year = performances.year
    where players.id = 20728
    
ORDER BY
    players.id,
    salaries.year DESC,
    performances.HR DESC,
    salaries.salary DESC;

    -- Todd Zeile id = 20728

