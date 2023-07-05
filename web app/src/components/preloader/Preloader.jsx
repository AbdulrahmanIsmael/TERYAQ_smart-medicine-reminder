import preloaderGif from '../../assets/preloader.gif';

function Preloader() {
  return (
    <div className='preloader'>
      <img src={preloaderGif} alt='Preloader' />
    </div>
  );
}

export default Preloader;
