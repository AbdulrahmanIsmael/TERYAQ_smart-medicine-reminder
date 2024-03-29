import './TeamMember.scss';

// eslint-disable-next-line react/prop-types
function TeamMember({ name, position, description, image }) {
  return (
    <div className='member-wrapper'>
      <div className='member__image'>
        <img src={image} alt={name} />
      </div>

      <div className='member__info'>
        <h2>{name} </h2>
        <h3>{position}</h3>
      </div>
    </div>
  );
}

export default TeamMember;
